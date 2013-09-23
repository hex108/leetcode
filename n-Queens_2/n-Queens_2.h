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
    /* 'queens_record' is taking advantage of symmetry for optimization. 
     */
    vector<int> queens_record;

    /* For every Queen whose coordinate is (x0, y0), if there is another Queen
     * whose coordinate is (x1, y1) satifies abs(x1 - x0) == abs(y1 - y0), 
     * they could attack each other. 
     * In order to check whether there is an Queen could attack it, we just need
     * check, whether there is a Queen on the line y = -x + (y0 + x0), x = x0 
     * and line y = x + (y0 - x0). There is a easy way to do it, for every Queen,
     * we use following variable to record the occupied lines.
     *
     * 'left_line_record' records line y = x + (y0 - x0)
     * 'right_line_record' records line y = x + (y0 + x0)
     * 'vertical_line_record' records line x = x0
     */
    vector<bool> left_line_record;
    vector<bool> right_line_record;
    vector<bool> vertical_line_record;
    int queens_num;

    void init(int n){
        left_line_record.clear();
        left_line_record.resize(2 * n - 1, false);

        right_line_record.clear();
        right_line_record.resize(2 * n - 1, false);

        vertical_line_record.clear();
        vertical_line_record.resize(n, false);

        queens_record.clear();
        queens_record.resize(n, 0);

        queens_num = n;
    }

    int total_n_queens(int start, int end){
        if(start > end)
            return 1;

        int total_num = 0;

        // try i-th column
        for(int i = 0; i <= end; i ++){
            if(start == 0 && 2 * i > end){
                total_num += queens_record[end - i];
                continue;
            }

            if(be_attacked(start, i) == true)
                continue;

            set_line_record(start, i);

            int num = total_n_queens(start + 1, end);
            if(start == 0)
                queens_record[i] = num;

            unset_line_record(start, i);
            
            total_num += num;
        }

        return total_num;
    }
    
    void set_line_record(int cur_row, int cur_column){
        left_line_record[cur_column - cur_row + (queens_num - 1)] = true;
        right_line_record[cur_column + cur_row] = true;
        vertical_line_record[cur_column] = true;
    }
    
    void unset_line_record(int cur_row, int cur_column){
        left_line_record[cur_column - cur_row + (queens_num - 1)] = false;
        right_line_record[cur_column + cur_row] = false;
        vertical_line_record[cur_column] = false;
    }
    
    bool be_attacked(int cur_row, int cur_column){
        if(left_line_record[cur_column - cur_row + (queens_num - 1)] == true 
            || right_line_record[cur_column + cur_row] == true 
            || vertical_line_record[cur_column] == true) 
            return true;
        else
            return false;
    }
    
public:
    int totalNQueens(int n) {
        init(n);

        return total_n_queens(0, n - 1); 
    }
};

/* Time Limit Exceed.
class Solution {
    int total_n_queens(int start, int end, 
                 vector<int> pre_queens, vector<bool> record){
        if(start > end)
            return 1;

        int total_num = 0;

        pre_queens.push_back(-1); // just add one to pre_queens's size
        // try i-th column
        for(int i = 0; i <= end; i ++){
            if(record[i] == true || be_attacked(pre_queens, start, i) == true)
                continue;
            
            pre_queens[start] = i;
            record[i] = true;

            total_num += total_n_queens(start + 1, end, pre_queens, record);

            record[i] = false;
        }

        return total_num;
    }
    
    bool be_attacked(vector<int> pre_queens, int cur_row, int cur_column){
        for(int i = 0; i < (int)pre_queens.size(); i ++){
            int tmp_row = i;
            int tmp_column = pre_queens[i];

            if(cur_row - tmp_row == abs(cur_column - tmp_column))
                return true;
        }

        return false;
    }
    
public:
    int totalNQueens(int n) {
        // 'pre_locations' records previos queens's locations(column).
        vector<int> pre_queens;
        // 'record' records whether i-th column has been occupied.
        vector<bool> record(n, false);

        return total_n_queens(0, n - 1, pre_queens, record); 
    }
};
*/
