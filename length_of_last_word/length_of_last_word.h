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
    void skip_spaces(const char *&s){
        while(*s == ' ')
            s ++;
    }

    int skip_words(const char *&s){
        int len = 0; 

        while(*s != 0 && *s != ' '){
            s ++;
            len ++;
        }

        return len;
    }

public:
    int lengthOfLastWord(const char *s) {
        if(s == NULL)
            return 0;

        int pre_length = 0;
        while(*s){
            skip_spaces(s); 

            int len = skip_words(s);
            if(len != 0)
                pre_length = len;
        }

        return pre_length;
    }
};
