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

    // Each row must have the numbers 1-9 occuring just once. 
    bool valid_row(vector<vector<char> > &board){
        for(size_t i = 0; i < size; i ++){
            set<char> record;
            for(size_t j = 0; j < size; j ++){
                char c = board[i][j];
                if(c == '.')
                    continue;

                if(c < '1' || c > '9')
                    return false;

                if(record.count(c))
                    return false;
                else
                    record.insert(c);
            }
        }

        return true;
    }

    // Each column must have the numbers 1-9 occuring just once. 
    bool valid_column(vector<vector<char> > &board){
        for(size_t i = 0; i < size; i ++){
            set<char> record;
            for(size_t j = 0; j < size; j ++){
                char c = board[j][i];
                if(c == '.')
                    continue;

                if(record.count(c))
                    return false;
                else
                    record.insert(c);
            }
        }

        return true;
    }

    /* the numbers 1-9 must occur just once in each of the 9 sub-boxes 
     * of the grid. 
     */
    bool valid_sub_boxes(vector<vector<char> > &board){
        for(size_t i = 0; i < size; i += 3){
            for(size_t j = 0; j < size; j +=3){
                if(!valid_sub_box(board, i, j))
                    return false;
            }
        }

        return true;
    }

    bool valid_sub_box(vector<vector<char> > &board, size_t row, size_t column){
        set<char> record;
        for(size_t i = row; i < row + 3; i ++){
            for(size_t j = column; j < column + 3; j ++){
                char c = board[j][i];
                if(c == '.')
                    continue;

                if(record.count(c))
                    return false;
                else
                    record.insert(c);
            }
        }

        return true;
    }

public:
    bool isValidSudoku(vector<vector<char> > &board) {
        size = 9;

        if(board.size() != size || board[0].size() != size)
            return false;

        if(valid_row(board) && valid_column(board) && valid_sub_boxes(board))
            return true;
        else
            return false;
    }
};
