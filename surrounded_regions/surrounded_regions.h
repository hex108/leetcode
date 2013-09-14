/* Notes:
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <algorithm>

#include "test.h"
using namespace std;

class Solution {
    // record the part 'O' in board which could touch the boarder by surrounded 'O'
    vector<vector<bool> > record;
    // row and column of board
    size_t row; 
    size_t column; 

    void init(vector<vector<char> > &board){
        row = board.size();
        column = board[0].size();

        vector<bool> tmp(column, false);
        record.assign(row, tmp);
    }

    void fill_record(vector<vector<char> > &board){
        // first and last row
        for(size_t i = 0; i < column; i ++){
            expand(board, 0, i);
            expand(board, row - 1, i);
        }

        // first and last column
        for(size_t i = 1; i < row - 1; i ++){
            expand(board, i, 0);
            expand(board, i, column - 1);
        }
    }

    /* I guess the recursion version at the bottom caused stack overflow on the test 
     * system, so I convet it to non-recursion version, and it is easy. 
     */
    void expand(vector<vector<char> > &board, size_t cur_row, size_t cur_column){
        deque<pair<int, int> > to_be_searched;   
        to_be_searched.push_back(make_pair(cur_row, cur_column));

        while(to_be_searched.size() != 0){
            pair<int, int> tmp = to_be_searched.front();
            to_be_searched.pop_front();
            cur_row = tmp.first; 
            cur_column = tmp.second; 

            if(board[cur_row][cur_column] != 'O' 
               || record[cur_row][cur_column] == true)
                continue;

            record[cur_row][cur_column] = true;

            /* expand up, down, left, right
             */
            // up
            if(cur_row > 0)
                to_be_searched.push_back(make_pair(cur_row - 1, cur_column));
            // down
            if(cur_row < row - 1)
                to_be_searched.push_back(make_pair(cur_row + 1, cur_column));
            // left
            if(cur_column > 0)
                to_be_searched.push_back(make_pair(cur_row, cur_column - 1));
            // right
            if(cur_column < column - 1)
                to_be_searched.push_back(make_pair(cur_row, cur_column + 1));
        }
    }

    void flip(vector<vector<char> > &board){
        for(size_t i = 1; i < row - 1; i ++){
            for(size_t j = 1; j < column - 1; j ++){
                if(board[i][j] == 'O' && record[i][j] == false)
                    board[i][j] = 'X';
            }
        }
    }

public:
    /* If the 'O' in board could not touch the boarder by surrounded 'O',
     * it must be surrounded by 'X', otherwise it must not be.
     */
    void solve(vector<vector<char> > &board) {
        if(board.size() == 0)
            return;

        init(board);
        fill_record(board); 
        flip(board);
    }
};

/* It will cause stack overflow.
void expand(vector<vector<char> > &board, size_t cur_row, size_t cur_column){
    if(board[cur_row][cur_column] != 'O' 
       || record[cur_row][cur_column] == true)
        return;

    record[cur_row][cur_column] = true;

    // expand up, down, left, right
    // up
    if(cur_row > 0)
        expand(board, cur_row - 1, cur_column);
    // down
    if(cur_row < row - 1)
        expand(board, cur_row + 1, cur_column);
    // left
    if(cur_column > 0)
        expand(board, cur_row, cur_column - 1);
    // right
    if(cur_column < column - 1)
        expand(board, cur_row, cur_column + 1);
}
*/

