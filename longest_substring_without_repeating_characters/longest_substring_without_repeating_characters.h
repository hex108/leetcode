/* Notes:
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
using namespace std;

class Solution {
    void init_record(int record[], int n){
        for(int i = 0; i < n; i ++){
            record[i] = -1;
        }
    }

    int get_max(int i, int j){
        if(i >= j)
            return i;
        else
            return j;
    }

public:
    int lengthOfLongestSubstring(string s) {
        const int n_charactres = 256;
        int record[n_charactres] = {0}; 

        init_record(record, n_charactres);

        int start = 0, max_len = 0;
        size_t i;
        for(i = 0; i < s.size(); i ++){
            int c = (int)s[i];
            if(record[c] >= start){ // A repeat in [start, i]
                max_len = get_max(max_len, i - start); // [start, i-1].
                start = record[c] + 1;
            }
            record[c] = i;
        }

        max_len = get_max(max_len, i - start); // [start, s.size())

        return max_len;
    }
};
