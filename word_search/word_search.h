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
    /* 'record' records whether board[i][j] has been visited once.
     */
    vector<vector<bool> > record;

    void init_record(vector<vector<char> > board){
        record.clear();

        size_t n = board[0].size(); 
        vector<bool> tmp(n, false);
        record.assign(board.size(), tmp);
    }

    bool find_string(vector<vector<char> > &board, int i, int j, string word){
        if(word == "")
            return true;

        char c = word[0];
        string sub_word = word.substr(1);

        // up
        if(i - 1 >= 0 && record[i - 1][j] == false && board[i - 1][j] == c){
            record[i - 1][j] = true;
            if(find_string(board, i - 1, j, sub_word))
                return true;
            record[i - 1][j] = false;
        }

        // down
        if(i + 1 < board.size() && record[i + 1][j] == false && board[i + 1][j] == c){
            record[i + 1][j] = true;
            if(find_string(board, i + 1, j, sub_word))
                return true;
            record[i + 1][j] = false;
        }

        // left
        if(j - 1 >= 0 && record[i][j - 1] == false && board[i][j - 1] == c){
            record[i][j - 1] = true;
            if(find_string(board, i, j - 1, sub_word))
                return true;
            record[i][j - 1] = false;
        }

        // right
        if(j + 1 < board[0].size() && record[i][j + 1] == false && board[i][j + 1] == c){
            record[i][j + 1] = true;
            if(find_string(board, i, j + 1, sub_word))
                return true;
            record[i][j + 1] = false;
        }

        return false;
    }

public:
    bool exist(vector<vector<char> > &board, string word) {
        if(board.size() == 0)
            return word == "";

        init_record(board);

        int row = board.size();
        int column = board[0].size();
        for(int i = 0; i < row; i ++){
            for(int j = 0; j < column; j ++){
                if(board[i][j] != word[0])
                    continue;

                record[i][j] = true;

                if(find_string(board, i, j, word.substr(1)))
                    return true;

                record[i][j] = false; // restore it.
            }
        }
    }
};
