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
    int add(int a, int &addtion_carry){
        int result = a + addtion_carry;

        if(result >= 10){
            result = result - 10;
            addtion_carry = 1;
        }else
            addtion_carry = 0;

        return result;
    }

public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> addtion_results(digits);

        int addtion_carry = 1;
        for(int i = digits.size() - 1; i >= 0; i --){
            addtion_results[i] =  add(digits[i], addtion_carry);

            if(addtion_carry == 0)
                break;
        }

        if(addtion_carry)
            addtion_results.insert(addtion_results.begin(), 1);

        return addtion_results;
    }
};
