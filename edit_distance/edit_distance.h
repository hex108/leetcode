/* Notes: Time Limit Exceeded when not using record.
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

    int getMinDistance(string word1, size_t start1, string word2, size_t start2){
        if(record[start1][start2] != -1)
            return record[start1][start2];
    
        if(word1 == word2){
            record[start1][start2] = 0;
            return 0;
        }else if(word1.size() == 0){
            record[start1][start2] = word2.size();
            return record[start1][start2];
        }else if(word2.size() == 0){
            record[start1][start2] = word1.size();
            return record[start1][start2];
        }

        if(word1[0] == word2[0]){
            int n = getMinDistance(word1.substr(1), start1 + 1, word2.substr(1), start2 + 1);
            record[start1][start2] = n;

            return n;
        }else{
            // Insert a character same as word2[0] to word1
            int min = getMinDistance(word1, start1, word2.substr(1), start2 + 1) + 1;

            // Delete a character from word1 
            int tmp_min = getMinDistance(word1.substr(1), start1 + 1, word2, start2) + 1;
            if(tmp_min < min)
                min = tmp_min;

            // Replace a character: word1[0] = word2[0]
            tmp_min = getMinDistance(word1.substr(1), start1 + 1, word2.substr(1), start2 + 1) + 1;
            if(tmp_min < min)
                min = tmp_min;

            record[start1][start2] = min;

            return min;
        }
    }
public:
    int minDistance(string word1, string word2){
        size_t len1 = word1.size();
        size_t len2 = word2.size();

        if(len1 == 0)
            return len2;
        if(len2 == 0)
            return len1;

        record.clear();
        vector<int> tmp(len2 + 1, -1);
        record.resize(len1 + 1, tmp);

        return getMinDistance(word1, 0, word2, 0);
    }
};
