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
    // 'minimum[i]' records the minimum value in height[i...height.size() - 1.
    vector<int> minimum;

    void init(vector<int> &height){
        int end = height.size();

        minimum.clear();
        minimum.resize(end, 0);

        int min = INT_MAX;
        for(int i = end - 1; i >= 0; i --){
            if(height[i] < min)
                min = height[i];
            minimum[i] = min;
        }
    }

    // compute the max area whose left side is from height[start].
    int get_mar_area(vector<int> &height, int start){
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

public:
    int largestRectangleArea(vector<int> &height) {
        init(height);

        // records the max area
        int max = 0;

        // compute the max area whose left side starts from height[i].
        for(size_t i = 0; i < height.size(); i ++){
            /* if height[i] <= height[i - 1], the area of a[i-1 ... j] must be
             * lareger than a[i ... j] for any j > i. 
             */
            if(i > 0 && height[i] <= height[i - 1])
                continue;

            int cur_max = get_mar_area(height, i);
            if(cur_max > max)
                max = cur_max;
        }

        return max;
    }
};
