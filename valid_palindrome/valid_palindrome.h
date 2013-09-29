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
public:
    bool isPalindrome(string s) {
        int len = s.size();

        if(len <= 1)
            return true;

        for(int i = 0, j = len - 1; i < j; i ++, j --){
            while(i < j && !isalnum(s[i]))
                i ++;
            if(i >= j)
                return true;

            while(j > i && !isalnum(s[j]))
                j --;

            if(j <= i)
                return true;

            if(tolower(s[i]) != tolower(s[j]))
                return false;
        }

        return true;
    }
};
