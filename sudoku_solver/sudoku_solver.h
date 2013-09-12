/* Notes:
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

#include "test.h"

using namespace std;

class Solution {
    size_t size;

    bool fill_board(vector<vector<char> > &board, size_t row, size_t column){
        while(row < 9 && board[row][column] != '.')
            get_next_column(row, column);

        //cout << "row = " << row << ", column = " << column << endl;

        if(row >= 9)
            return true;

        set<char> record;   

        fill_record(board, row, column, record);

        for(char c = '1'; c <= '9'; c ++){
            if(record.count(c))
                continue;

            board[row][column] = c;
            
            size_t next_row = row, next_column = column;
            get_next_column(next_row, next_column);

            if(fill_board(board, next_row, next_column))
                return true;

            board[row][column] = '.';
        }

        return false;
    }

    void get_next_column(size_t &row, size_t &column){
        column ++;
        if(column >= 9){
            row ++;
            column = 0;
        }
    }

    void fill_record(vector<vector<char> > &board, size_t row, size_t column, set<char> &record){
        // row
        for(size_t i = 0; i < size; i ++){
            char c = board[row][i];
            if(c != '.')
                record.insert(c);
        }

        // column
        for(size_t i = 0; i < size; i ++){
            char c = board[i][column];
            if(c != '.')
                record.insert(c);
        }

        // sub-box
        size_t start_row = (row / 3) * 3;
        size_t start_column = (column / 3) * 3;
        for(size_t i = start_row; i < start_row + 3; i ++){
            for(size_t j = start_column; j < start_column + 3; j ++){
                char c = board[i][j];
                if(c != '.')
                    record.insert(c);
            }
        }
    }

public:
    void solveSudoku(vector<vector<char> > &board) {
        size = 9;

        fill_board(board, 0, 0);     
    }
};
