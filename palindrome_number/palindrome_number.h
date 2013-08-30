/* Notes:
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;

        int divisor = 1;
        for(int tmp = x; tmp >= 10; tmp = tmp / 10){
            divisor *= 10;
        }

        int n1, n2;
        n1 = n2 = x;
        while(n1 && n2){
            if((n1 / divisor) != (n2 % 10))
                return false;

            n1 = n1 % divisor;
            divisor = divisor / 10;
            n2 = n2 / 10;
        }

        return n1 == n2;
    }
};
