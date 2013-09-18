/* Notes:
 *
 */
#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
#include <cmath>

#include "test.h"
using namespace std;

class Solution {
    /* record the number of ones in column starts from matrix[i][j] to 
     * matrix[matrix.size() - 1, j].
     */
    vector<vector<int> > num_of_ones;

    void init(vector<vector<char> > &matrix){
        num_of_ones.clear();

        int row = matrix.size();
        int column = matrix[0].size();

        vector<int> tmp(column, 0);
        num_of_ones.resize(row + 1,  tmp);  // make last row as inital value.
        
        for(int i = row - 1; i >= 0; i --){
            for(int j = 0; j < column; j ++){
                if(matrix[i][j] == '1')
                    num_of_ones[i][j] = num_of_ones[i + 1][j] + 1;
                else
                    num_of_ones[i][j] = 0;
            }
        }
    }

    int get_maximal_rectangle_at_row(vector<int> &height){
        // 'minimum[i]' records the minimum value in height[i...height.size() - 1.
        vector<int> minimum(height.size(), 0);

        int min = INT_MAX;
        for(int i = (int)minimum.size() - 1; i >= 0; i --){
            if(height[i] < min)
                min = height[i];
            minimum[i] = min;
        }

        // records the max area
        int max = 0;

        // compute the max area whose left side starts from height[i].
        for(size_t i = 0; i < height.size(); i ++){
            /* if height[i] <= height[i - 1], the area of a[i-1 ... j] must be
             * lareger than a[i ... j] for any j > i. 
             */
            if(i > 0 && height[i] <= height[i - 1])
                continue;

            int cur_max = get_max_from_start(height, i, minimum);
            if(cur_max > max)
                max = cur_max;
        }

        return max;
    }
    
    // compute the max area whose left side is from height[start].
    int get_max_from_start(vector<int> &height, int start, vector<int> &minimum){
        if(height[start] == minimum[start])
            return height[start] * (height.size() - start);

        int cur_max = 0;
        int tmp_max = 0;

        int min_height = height[start]; // records the miminum_height in height[start ... j]
        for(int j = start; j < (int)height.size(); j ++){
            int h = height[j];
            /* if h < min_height, we will discard previous tmp_max because 
             * 'min_height' need be freshed now. But height[start ... j] 
             * might be the max area compared with areas whose left side
             * starts from 'start', so we need compare it('tmp_max') with
             * 'cur_max'.
             */
            if(h < min_height){
                if(tmp_max > cur_max)
                    cur_max = tmp_max;

                min_height = h;
                tmp_max = min_height * (j - start + 1);
            }else{
                tmp_max += min_height;
            }
        }

        if(tmp_max > cur_max)
            cur_max = tmp_max;

        return cur_max;
    }

    // if v1[i] == '1' for i, v2[i] == '1', then v1 is a subset of v2.
    bool is_subset(vector<char> &v1, vector<char> &v2){
        for(size_t i = 0; i < v1.size(); i ++){
            if(v1[i] == '1' && v2[i] != '1')
                return false;
        }

        return true;
    }

public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.size() == 0)
            return 0;

        init(matrix); 

        int max = 0;
        int remain_row = matrix.size();
        int column = matrix[0].size();
        for(size_t i = 0; i < matrix.size(); i ++){
            if(remain_row * column <= max)
                break;

            if(i >= 1 && is_subset(matrix[i], matrix[i - 1]))
                continue;

            remain_row --;
                
            int tmp_max = get_maximal_rectangle_at_row(num_of_ones[i]); 
            if(tmp_max > max)
                max = tmp_max;
        }

        return max;
    }
};
