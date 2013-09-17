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
    vector<int> grayCode(int n) {
        vector<int> gray_codes;

        if(n > 32) // vector<int> could only hold 32bits element
            return gray_codes; 

        unsigned int max = pow(2, n) - 1; 
        for(unsigned int i = 0; i <= max; i ++){
            int val = (i / 2) ^ i;
            gray_codes.push_back(val);
        }

        return gray_codes;
    }
};

/* error
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> gray_codes;

        if(n > 32) // vector<int> could only hold 32bits element
            return gray_codes; 

        int val = 0;

        for(int i = 0; i < n; i ++){
            gray_codes.push_back(val);

            // turn to 11...1
            unsigned int tmp = 1;
            unsigned int max = pow(2, i + 1) - 1; 
            while((tmp & val) == 0 && tmp <= max){
                val |= tmp;
                gray_codes.push_back(val);

                tmp = tmp << 1;
            }

            if(i == n - 1)
                break;

            // turn to 10...0
            unsigned int tmp2 = 1; // 1...10
            unsigned int min = 1 << i; 
            while((unsigned int)val > min){
                val &= ~tmp2;
                gray_codes.push_back(val);

                tmp2 = tmp2 << 1;
            }

            // turn to 110...0
            val |= 1 << (i + 1);
        }

        return gray_codes;
    }
};
*/
