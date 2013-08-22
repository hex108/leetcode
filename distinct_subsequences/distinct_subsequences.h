/* Notes: Record the value that needs computed many times. It is a very good way
 * to save time. 
 */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
using namespace std;

class Solution {
    vector<vector<int> > record;

    int getNumDistinct(string S, size_t index_s, string T, size_t index_t) {
        if(record[index_s][index_t] != -1)
            return record[index_s][index_t];

        size_t len_S = S.size();
        size_t remain_size_T = T.size() - index_t;

        if(remain_size_T == 1){
            record[index_s][index_t] = count(S.begin() + index_s, S.end(), T[index_t]);

            return record[index_s][index_t];
        }

        int num = 0;

        for(size_t i = index_s; len_S - i >= remain_size_T; i ++){
            if(S[i] == T[index_t]){
                num += getNumDistinct(S, i + 1, T, index_t + 1);
            }
        }

        record[index_s][index_t] = num;

        return num;
    }
public:
    int numDistinct(string S, string T) {
        if(T.size() == 0)
            return -1;

        if(S.size() == 0)
            return 0;

        record.clear();
        vector<int> tmp(T.size(), -1);
        record.resize(S.size(), tmp);

        return getNumDistinct(S, 0, T, 0);
    }
};

/*
// The following algorihtm does not use record. It spends more time.
class Solution {
public:
    int numDistinct(string S, string T) {
        size_t len_S = S.size();
        size_t len_T = T.size();

        if(len_T == 1){
            return count(S.begin(), S.end(), T[0]);
        }else if(len_T == 0){
            return -1;
        }

        int num = 0;

        for(size_t i = 0; len_S - i >= len_T; i ++){
            if(S[i] == T[0]){
                num += numDistinct(S.substr(i + 1), T.substr(1));
            }
        }

        return num;
    }
};
 */
