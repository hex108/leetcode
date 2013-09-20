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

    void init(vector<vector<int> > &obstacleGrid){
        int row = obstacleGrid.size();
        int column = obstacleGrid[0].size();
        record.clear();
        vector<int> tmp(column, -1);
        record.resize(row, tmp);

        // initial record[m - 1][0 ... n - 1]
        int num = 1;
        for(int i = column - 1; i >= 0; i --){
            if(obstacleGrid[row - 1][i] == 1)
                num = 0;

            record[row - 1][i] = num;
        }

        // initial record[0 ... row - 1][column - 1]
        num = 1;
        for(int i = row - 1; i >= 0; i --){
            if(obstacleGrid[i][column - 1] == 1)
                num = 0;

            record[i][column - 1] = num;
        }
    }

    int get_unique_path_num(vector<vector<int> > &obstacleGrid, int cur_row,
                            int cur_column){
        if(obstacleGrid[cur_row][cur_column] == 1)
            return 0;

        if(record[cur_row][cur_column] != -1)
            return record[cur_row][cur_column];

        // case 1: move down
        int n1 = get_unique_path_num(obstacleGrid, cur_row + 1, cur_column);
        // case 2: move right
        int n2 = get_unique_path_num(obstacleGrid, cur_row, cur_column + 1);

        // total paths number
        int n = n1 + n2;
        record[cur_row][cur_column] = n;

        return n;
    }   
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.size() == 0)
            return 0;

        init(obstacleGrid);

        return get_unique_path_num(obstacleGrid, 0, 0);
    }
};
