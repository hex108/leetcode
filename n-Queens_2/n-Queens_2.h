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
    vector<vector<int> > queens_record;
    bool symmetry_start = false; 

    int total_n_queens(int start, int end, 
                 vector<int> pre_queeens, vector<bool> record){
        if(start > end)
            return 1;

        int total_num = 0;

        pre_queeens.push_back(-1); // just add one to pre_queeens's size
        // try i-th column
        for(int i = 0; i <= end; i ++){
            if(start == 0 && 2 * i >= end)
                symmetry_start = true;

            if(record[i] == true || be_attacked(pre_queeens, start, i) == true)
                continue;
            
            pre_queeens[start] = i;
            record[i] = true;

            int num;
            if(queens_record[start][end - i] != -1 && sy)
                num = queens_record[start][end - i];
            else{
                num = total_n_queens(start + 1, end, pre_queeens, record);
                queens_record[start][i] = num;
            }
            
            total_num += num;

            record[i] = false;
        }

        return total_num;
    }
    
    bool be_attacked(vector<int> pre_queeens, int cur_row, int cur_column){
        for(int i = 0; i < (int)pre_queeens.size(); i ++){
            int tmp_row = i;
            int tmp_column = pre_queeens[i];

            if(cur_row - tmp_row == abs(cur_column - tmp_column))
                return true;
        }

        return false;
    }
    
public:
    int totalNQueens(int n) {
        // 'pre_locations' records previos queens's locations(column).
        vector<int> pre_queeens;
        // 'record' records whether i-th column has been occupied.
        vector<bool> record(n, false);

        vector<int> tmp(n, -1);
        queens_record.clear();
        queens_record.resize(n, tmp);

        return total_n_queens(0, n - 1, pre_queeens, record); 
    }
};

/* Time Limit Exceed.
class Solution {
    int total_n_queens(int start, int end, 
                 vector<int> pre_queeens, vector<bool> record){
        if(start > end)
            return 1;

        int total_num = 0;

        pre_queeens.push_back(-1); // just add one to pre_queeens's size
        // try i-th column
        for(int i = 0; i <= end; i ++){
            if(record[i] == true || be_attacked(pre_queeens, start, i) == true)
                continue;
            
            pre_queeens[start] = i;
            record[i] = true;

            total_num += total_n_queens(start + 1, end, pre_queeens, record);

            record[i] = false;
        }

        return total_num;
    }
    
    bool be_attacked(vector<int> pre_queeens, int cur_row, int cur_column){
        for(int i = 0; i < (int)pre_queeens.size(); i ++){
            int tmp_row = i;
            int tmp_column = pre_queeens[i];

            if(cur_row - tmp_row == abs(cur_column - tmp_column))
                return true;
        }

        return false;
    }
    
public:
    int totalNQueens(int n) {
        // 'pre_locations' records previos queens's locations(column).
        vector<int> pre_queeens;
        // 'record' records whether i-th column has been occupied.
        vector<bool> record(n, false);

        return total_n_queens(0, n - 1, pre_queeens, record); 
    }
};
*/
