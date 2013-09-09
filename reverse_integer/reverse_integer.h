/* Notes:
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <climits>

#include "test.h"
using namespace std;

class Solution {
public:
    // how to return an error code?!
    int reverse(int x) {
        unsigned int n = x;
        int sign = 1;

        if(x < 0){
            n = -x;
            sign = -1;
        }

        unsigned int ret = 0;
        /* 'limit' is used to judge whether overflow. It is unused now because
         * there is no error code I could return.
         */
        // unsigned int limit = UINT_MAX / 10;

        while(n){
            ret = ret * 10 + n % 10;
            n = n / 10;
        }

        return sign * ret;
    }
};
