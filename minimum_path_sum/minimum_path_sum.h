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
    // record[i][j] records the min sum from grid[i][j] to the bottom right.
    vector<vector<int> > record;

    void init(vector<vector<int> > &grid){
        int row = grid.size();
        int column = grid[0].size();

        vector<int> tmp(column, -1);
        record.clear();
        record.resize(row, tmp);

        // initial record[row][0 ... column - 1]
        int sum = 0; 
        for(int i = column - 1; i >= 0; i --){
            sum += grid[row - 1][i];
            record[row - 1][i] = sum;
        }

        // initial record[0 ... row - 1][column - 1]
        sum = 0; 
        for(int i = row - 1; i >= 0; i --){
            sum += grid[i][column - 1];
            record[i][column - 1] = sum;
        }
    }

    int get_min_path_sum(vector<vector<int> > &grid, size_t cur_row, 
                        size_t cur_column){
        if(record[cur_row][cur_column] != -1)
            return record[cur_row][cur_column]; 

        // case 1: move down
        int sum1 = get_min_path_sum(grid, cur_row + 1, cur_column);
        // case 2: move right
        int sum2 = get_min_path_sum(grid, cur_row, cur_column + 1);

        int min = sum1 <= sum2? sum1 : sum2;
        
        record[cur_row][cur_column] = min + grid[cur_row][cur_column];

        return record[cur_row][cur_column]; 
    }

public:
    int minPathSum(vector<vector<int> > &grid) {
        if(grid.size() == 0)
            return 0;

        init(grid); 

        return get_min_path_sum(grid, 0, 0);
    }
};
