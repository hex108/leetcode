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
    map<int, bool> column_record;

    void set_zeroes_to_row(vector<vector<int> > &matrix, size_t cur_row){
        for(size_t i = 0; i < matrix[0].size(); i ++){
            if(matrix[cur_row][i] == 0)
                column_record[i] = true;
            else
                matrix[cur_row][i] = 0;
        }
    }

    void set_zeroes_to_column(vector<vector<int> > &matrix){
        map<int, bool>::iterator it;
        for(it = column_record.begin(); it != column_record.end(); it ++){
            int column = it->first;
            for(size_t i = 0; i < matrix.size(); i ++){
                if(matrix[i][column] != 0)
                    matrix[i][column] = 0;
            }
        }
    }
public:
    void setZeroes(vector<vector<int> > &matrix) {
        size_t row = matrix.size();
        if(row <= 0)
            return;

        column_record.clear();

        size_t column = matrix[0].size();
        for(size_t i = 0; i < row; i ++){
            for(size_t j = 0; j < column; j ++){
                if(matrix[i][j] == 0){
                    set_zeroes_to_row(matrix, i);
                    break;
                }
            }
        }

        set_zeroes_to_column(matrix);
    }
};
