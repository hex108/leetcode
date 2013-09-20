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
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> numbers;
        if(matrix.size() == 0)
            return numbers;

        int row = matrix.size();
        int column = matrix[0].size();

        // first is row, and second is column.
        pair<int, int> top_left(0, 0), top_right(0, column - 1);
        pair<int, int> bottom_left(row - 1, 0), bottom_right(row - 1, column - 1);

        while(top_left.second <= top_right.second 
              && top_left.first <= bottom_left.first){
            // top: left -> right 
            int cur_row = top_left.first;  
            for(int i = top_left.second; i <= top_right.second; i ++)
                numbers.push_back(matrix[cur_row][i]);

            // right: top -> down
            int cur_column = top_right.second;
            for(int i = top_right.first + 1; i <= bottom_right.first; i ++)
                numbers.push_back(matrix[i][cur_column]);

            // bottom: right -> left
            if(bottom_right.first == cur_row)
                break;
            else
                cur_row = bottom_right.first;
            for(int i = bottom_right.second - 1; i >= bottom_left.second; i --)
                numbers.push_back(matrix[cur_row][i]);

            // left: down ->top
            if(bottom_left.second == cur_column)
                break;
            else
                cur_column = bottom_left.second;
            for(int i = bottom_left.first - 1; i > top_left.first; i --)
                numbers.push_back(matrix[i][cur_column]);

            top_left.first ++;
            top_left.second ++;
            top_right.first ++; 
            top_right.second --;

            bottom_left.first --;
            bottom_left.second ++;
            bottom_right.first --;
            bottom_right.second --;
        }

        return numbers;
    }
};
