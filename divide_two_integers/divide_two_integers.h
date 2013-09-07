/* Notes:
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>

#include "test.h"
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long new_dividend = dividend;
        long long new_divisor = divisor;

        int sign = 1;
        if(dividend < 0){
            new_dividend = -new_dividend;
            sign = -sign;
        }

        if(new_divisor < 0){
            new_divisor = -new_divisor;
            sign = -sign;
        }

        // find a max_exp that new_divisor * pow(2, max_exp - 1) < new_dividend
        // && new_divisor * pow(2, max_exp) >= new_dividend
        int max_exp = 0;
        long long num = new_divisor;
        while(num <= new_dividend){
            num = num * 2;
            max_exp ++;
        }

        max_exp --;

        int quotient = 0;
        while(new_dividend >= new_divisor){
            long long n = pow(2, max_exp);
            long long num = new_divisor * n;
            while(new_dividend >= num){
                new_dividend = new_dividend - num;
                quotient = quotient + n;
            }
            
            max_exp --;
        }

        return quotient * sign;
    }
};

/* memory limt exceeded.
class Solution {
public:
    int divide(int dividend, int divisor) {
        vector<int> record;
        // Init record: record[n] = divisor * pow(2, n))
        int num = divisor;
        while(num < dividend){
            record.push_back(num);
            num = num * 2;
        }
        record.push_back(num);

        int quotient = 0;
        int n = record.size();
        while(dividend > divisor){
            vector<int>::iterator it;
            it = lower_bound(record.begin(), record.begin() + n, dividend);
            it --; // then *it < dividend
            
            int index = it - record.begin();
            int n = pow(2, index);
            while(dividend > *it){
                quotient += n;
                dividend -= *it;
            }
        }

        return quotient;
    }
};
*/
