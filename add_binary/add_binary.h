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
    char add(char a, char b, int &addtion_carry){
        char c;

        if(addtion_carry){
            if(a == '1' && b == '1'){
                c = '1';
                addtion_carry = 1;
            }else if(a == '1' || b == '1'){
                c = '0';
                addtion_carry = 1;
            }else{
                c = '1';
                addtion_carry = 0;
            }
        }else{
            if(a == '1' && b == '1'){
                c = '0';
                addtion_carry = 1;
            }else if(a == '1' || b == '1'){
                c = '1';
                addtion_carry = 0;
            }else{
                c = '0';
                addtion_carry = 0;
            }
        }

        return c;
    }

public:
    string addBinary(string a, string b) {
        string c; 

        int i, j;
        int addtion_carry = 0;
        for(i = a.size() - 1, j = b.size() - 1; i >= 0 && j >= 0; i --, j --){
            c.push_back(add(a[i], b[j], addtion_carry));  
        }

        if(i >= 0){
            while(i >= 0){
                c.push_back(add(a[i], '0', addtion_carry));
                i --;
            }
        }else{
            while(j >= 0){
                c.push_back(add('0', b[j], addtion_carry));
                j --;
            }
        }

        if(addtion_carry)
            c.push_back('1');

        reverse(c.begin(), c.end());

        return c;
    }
};
