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
    int romanToInt(string s) {
        int num = 0;  

        for(size_t i = 0; i < s.size(); i ++){
            char c = s[i];

            switch(c){
                case 'M': 
                    num += 1000; 
                    break;
                case 'D':
                    num += 500;
                    break;
                case 'C':
                    if(i + 1 < s.size() && (s[i + 1] == 'D' || s[i + 1] == 'M')){
                        if(s[i + 1] == 'D')
                            num += 400;
                        else
                            num += 900;
                        
                        i ++;
                    }else
                        num += 100;
                    break;
                case 'L':
                    num += 50;
                    break;
                case 'X':
                    if(i + 1 < s.size() && (s[i + 1] == 'L' || s[i + 1] == 'C')){
                        if(s[i + 1] == 'L')
                            num += 40;
                        else
                            num += 90;
                        
                        i ++;
                    }else
                        num += 10;
                    break;
                case 'V':
                    num += 5;
                    break;
                case 'I':
                    if(i + 1 < s.size() && (s[i + 1] == 'V' || s[i + 1] == 'X')){
                        if(s[i + 1] == 'V')
                            num += 4;
                        else
                            num += 9;
                        
                        i ++;
                    }else
                        num += 1;
                    break;
                default: 
                    return 0;
            }
        }

        return num;
    }
};
