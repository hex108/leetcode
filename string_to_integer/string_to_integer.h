/* Notes:
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <ctype.h>
#include <climits>

#include "test.h"
using namespace std;

class Solution {
public:
    /* From: http://www.cplusplus.com/reference/cstdlib/atoi/?kw=atoi
     * The function first discards as many whitespace characters (as in isspace)
     * as necessary until the first non-whitespace character is found. Then, 
     * starting from this character, takes an optional initial plus or minus 
     * sign followed by as many base-10 digits as possible, and interprets them 
     * as a numerical value.
     *
     * The string can contain additional characters after those that form the 
     * integral number, which are ignored and have no effect on the behavior of 
     * this function.
     *
     * If the first sequence of non-whitespace characters in str is not a valid 
     * integral number, or if no such sequence exists because either str is empty 
     * or it contains only whitespace characters, no conversion is performed and 
     * zero is returned.
     *
     * Return Value:
     * On success, the function returns the converted integral number as an int 
     * value.
     * If the converted value would be out of the range of representable values 
     * by an int, it causes undefined behavior, for the problme requests,
     * INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
     */
    int atoi(const char *str) {
        unsigned int n = 0;
        int sign = 1;  
        
        while(isspace(*str))
            str ++;

        if(*str == 0)
            return 0;

        if(*str == '+' || *str == '-'){
            if(*str == '-')
                sign = -1;
            str ++;
        }
        
        unsigned int limit = UINT_MAX / 10;
        while(isdigit(*str)){
            if(limit <= n){
                n = UINT_MAX;
                break;
            }

            n = n * 10 + (*str - '0');
            str ++;
        }

        if(n >= INT_MAX){
            if(sign == 1)
                n = INT_MAX;
            else{
                if(n == INT_MAX)
                    n = -1 * n;
                else
                    n = INT_MIN;
            }

            return n;
        }

        return n * sign;
    }
};
