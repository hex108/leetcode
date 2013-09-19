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
    void skip_spaces(const char *&s){
        while(*s == ' ')
            s ++;
    }

    void skip_digits(const char *&s){
        while(isdigit(*s))
            s ++;
    }

public:
    /* [+-]?[0-9]+?.?[0-9]+?(e+?[0-9]+)?
     * but there is must a digit in it.
     */
    bool isNumber(const char *s) {
        bool has_digits = false;

        // strip first spaces
        skip_spaces(s);
        
        // '+' or '-'
        if(*s == '+' || *s == '-')
            s ++;

        // digits 
        if(isdigit(*s))
            has_digits = true;
        skip_digits(s);

        // point
        if(*s == '.')
            s ++;

        // digits
        if(isdigit(*s))
            has_digits = true;
        skip_digits(s);

        if(*s == 'e'){
            s ++;
            
            if(*s == '+' || *s == '-')
                s ++;

            // digits
            if(isdigit(*s) == false)
                return false;
            skip_digits(s);
        }

        // strip last spaces
        skip_spaces(s);

        return *s == 0 && has_digits;
    }
};
