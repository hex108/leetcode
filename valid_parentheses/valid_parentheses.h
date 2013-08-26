/* Notes:
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <stack>

#include "test.h"
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(size_t i = 0; i < s.size(); i ++){
            char c = s[i];

            if(c == '(' || c == '{' || c == '[')
                st.push(c);
            else{
                if(st.empty())
                    return false;

                char pre = st.top();
                st.pop();
                
                if((c == ')' && pre != '(') || (c == '}' && pre != '{') 
                    || (c == ']' && pre != '['))
                    return false;
            }
        }

        return st.empty();
    }
};
