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
    int sqrt(int x) {
        double old_guess = -1;
        double guess = 1;

        while(abs(guess - old_guess) > 0.1){
            old_guess = guess;
            guess = (guess + x / guess ) / 2;
        }

        return guess; 
    }
};
