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
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1)
            return s;

        // 'index' records the indexs from which to current index are palindrommic string.
        vector<int> index;
        index.push_back(1); // then we could compare s[1] with s[0].

        int start = -1, max_len = 0;

        for(size_t i = 1; i < s.size(); i ++){
            vector<int> tmp_index;
            /* this item is the left of the middle of the palindrommic string,
             * e.g. abccb, it is first 'c'.
             */
            tmp_index.push_back(i + 1); 
            /* this item is the middle of the palindrommic string,
             * e.g. abcba, it is 'c'.
             */
            tmp_index.push_back(i); 

            for(size_t j = 0; j < index.size(); j ++){
                // s[k, j-1] is a palindrommic string, 
                int k = index[j]; 
                // if s[i] == s[k - 1], then s[k - 1, j] is a palindrommic string.
                if(k - 1 >= 0 && s[i] == s[k - 1]){
                    tmp_index.push_back(k - 1);
                    int current_len = i - (k - 1) + 1;
                    if(current_len > max_len){
                        max_len = current_len;
                        start = k - 1;
                    } 
                }
            }

            index.swap(tmp_index);
        }

        if(start != -1)
            return s.substr(start, max_len);
        else // it means there is no palindrommic string more than two letters.
            return s.substr(0, 1);
        }
};
