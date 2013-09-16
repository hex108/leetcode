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

#include "test.h"
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0)
            return 0;

        /* For string s[0...n], suppose the number of decodings for s[0...n-1] 
         * is f0, and the number for s[n] is f1. If we want to add a char 
         * s[n + 1] to s, the number for s[0...n + 1] will be:
         * 1) 0  2) f0 3) f1 4) f0 + f1
         */

        /* f0 and f1 are set by need.
         * f0 represents the number for s[0 ... i - 2].
         * f1 represents the number for s[0 ... i - 1].
         */
        int f0 = 0; 
        int f1 = 1; 
        // then pre_char and cur_char could not be encoded together.
        char pre_char = '3';
        for(size_t i = 0; i < s.size(); i ++){
            int f2;
            char cur_char = s[i];
            // s[i] could only be encoded with s[i - 1];
            if(cur_char == '0'){
                if(pre_char != '1' && pre_char != '2')
                    return 0;
                // encode s[i - 1] and s[i] together
                f2 = f0;
            }else if(pre_char == '1' || (pre_char == '2' && cur_char <= '6')){
            /* s[i - 1] and s[i] could be encoded together and could be encoded
             * seperately.
             */
                f2 = f1 + f0;
            }else{
            // s[i - 1] and s[i] could only be encoded seperately.
                f2 = f1;
            }

            pre_char = cur_char;
            f0 = f1;
            f1 = f2;
        }

        return f1;
    }
};
