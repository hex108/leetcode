/* Notes:
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <algorithm>

#include "test.h"
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int max = 0, tmp_max = 0;
        int left_parentheses = 0; 
        vector<int> tmp_max_vector;

        for(size_t i = 0; i < s.size(); i ++){
            if(s[i] == '('){
                left_parentheses ++;
                tmp_max_vector.push_back(tmp_max);
            }else if(s[i] == ')'){
                if(left_parentheses){
                    tmp_max ++;
                    left_parentheses --;
                    tmp_max_vector.pop_back();
                }else{
                    max = tmp_max > max? tmp_max : max;
                    tmp_max = 0;
                    left_parentheses = 0;
                    tmp_max_vector.clear();
                }
            }
        }
        
        tmp_max_vector.push_back(tmp_max);

        int n1 = 0, n2 = 0;
        for(size_t i = 0; i < tmp_max_vector.size(); i ++){
            n2 = tmp_max_vector[i];

            int tmp = n2 - n1;
            max = tmp > max? tmp : max;

            n1 = n2;
        }

        return max * 2;
    }
};
