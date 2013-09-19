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
    // record[i][j] records the number of unique paths from (i,j) to (m-1, n-1) 
    vector<vector<int> > record;

    void init(int m, int n){
        record.clear();
        vector<int> tmp(n, -1);
        record.resize(m, tmp);

        // initial record[m - 1][0 ... n - 1]
        for(int i = 0; i < n; i ++)
            record[m - 1][i] = 1;

        // initial record[0 ... m - 1][n - 1]
        for(int i = 0; i < m; i ++)
            record[i][n - 1] = 1;
    }

    int get_unique_path_num(int cur_row, int cur_column){
        if(record[cur_row][cur_column] != -1)
            return record[cur_row][cur_column];

        // case 1: move down
        int n1 = get_unique_path_num(cur_row + 1, cur_column);
        // case 2: move right
        int n2 = get_unique_path_num(cur_row, cur_column + 1);

        // total paths number
        int n = n1 + n2;
        record[cur_row][cur_column] = n;

        return n;
    }   
public:
    /* It is acutually a combinatorial problem. The number of unique paths
     * is C(m + n - 2, m - 1) 
     * = (m * (m + 1) * ... * (m + n - 2)) / (1 * 2 * ... * (n - 1)).
     * But it is a little difficult to caculate, so we use other method.
     */
    int uniquePaths(int m, int n) {
        init(m, n);

        return get_unique_path_num(0, 0);
    }
};
