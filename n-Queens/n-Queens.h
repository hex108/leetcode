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
    vector<vector<string> > solve_n_queens(int start, int end, 
                 vector<int> pre_queeens, vector<bool> record){
        vector<vector<string> > queens;

        if(start > end){
            vector<string> tmp = get_n_queens(pre_queeens);
            queens.push_back(tmp);

            return queens;
        }

        pre_queeens.push_back(-1); // just add one to pre_queeens's size
        // try i-th column
        for(int i = 0; i <= end; i ++){
            if(record[i] == true || be_attacked(pre_queeens, start, i) == true)
                continue;
            
            pre_queeens[start] = i;
            record[i] = true;

            vector<vector<string> > tmp = solve_n_queens(start + 1, end, pre_queeens, record);
            queens.insert(queens.end(), tmp.begin(), tmp.end());

            record[i] = false;
        }

        return queens;
    }
    
    vector<string> get_n_queens(vector<int> queens_locations){
        size_t n = queens_locations.size();

        string s(n, '.');
        vector<string> queens(n, s);

        for(size_t i = 0; i < n; i ++){
            int loc = queens_locations[i];
            queens[i][loc] = 'Q';
        }

        return queens;
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
    vector<vector<string> > solveNQueens(int n) {
        // 'pre_locations' records previos queens's locations(column).
        vector<int> pre_queeens;
        // 'record' records whether i-th column has been occupied.
        vector<bool> record(n, false);

        return solve_n_queens(0, n - 1, pre_queeens, record); 
    }
};
