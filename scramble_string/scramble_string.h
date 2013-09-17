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
    bool contain_same_characters(string s1, string s2){
        map<char, int> characters;

        for(size_t i = 0; i < s1.size(); i ++){
            char c = s1[i];
            characters[c] ++;
        }

        for(size_t i = 0; i < s2.size(); i ++){
            char c = s2[i];
            if(characters[c] <= 0)
                return false;
            characters[c] --;
        }
        
        return true;
    }

public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2)
            return true;

        if(s1.size() == 1 && s1 != s2)
            return false;

        if(contain_same_characters(s1, s2) == false)
            return false;

        size_t size = s1.size();        
        for(size_t n = 1; n < size; n ++){
            // divide s1 to left and right parts: s1[0..n-1], s1[n..size-1]
            
            // do not swap left and right parts
            if(isScramble(s1.substr(0, n), s2.substr(0, n)) 
                && isScramble(s1.substr(n, size - n), s2.substr(n, size - n)))
                return true;

            // swap left and right parts
            if(isScramble(s1.substr(0, n), s2.substr(size - n, n))
                && isScramble(s1.substr(n, size - n), s2.substr(0, size -n)))
                return true;
        }

        return false;
    }
};
