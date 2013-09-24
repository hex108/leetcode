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
    string do_mutiply(string &num, char c){
        string product; 
         
        int carry = 0;
        int n1 = c - '0';
        for(int i = num.size() - 1; i >= 0; i --){
            int n2 = num[i] - '0';   
            int ret = n1 * n2 + carry;
            carry = ret / 10;

            product.push_back(ret % 10 + '0');
        }

        if(carry)
            product.push_back(carry + '0');

        return product;
    }

    string add(string &num1, string &num2){
        string num3;

        int carry = 0;
        size_t i;
        for(i = 0; i < num1.size() && i < num2.size(); i ++){
           int ret = (num1[i] - '0') + (num2[i] - '0') + carry;
           carry = ret / 10;

           num3.push_back(ret % 10 + '0');
        }

        // if i < num1.size()
        while(i < num1.size()){
           int ret = (num1[i] - '0') + carry;
           carry = ret / 10;

           num3.push_back(ret % 10 + '0');
           i ++;
        }

        // if i < num2.size() 
        while(i < num2.size()){
           int ret = (num2[i] - '0') + carry;
           carry = ret / 10;

           num3.push_back(ret % 10 + '0');
           i ++;
        }

        if(carry)
            num3.push_back(carry + '0');

        return num3;
    }

public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return string("0");

        string num3; 

        int offset = 0;
        for(int i = num2.size() - 1; i >= 0; i --){
            string tmp = do_mutiply(num1, num2[i]); 
            tmp.insert(tmp.begin(), offset, '0');
            offset ++;

            num3 = add(tmp, num3);
        }

        reverse(num3.begin(), num3.end());

        return num3;
    }
};
