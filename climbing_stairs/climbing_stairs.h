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
    int climbStairs(int n) {
        if(n <= 1)
            return n;
        
        //f(n) = f(n - 1) + f(n - 2);
        int f0 = 1, f1 = 1;
        int count = 2;
        int f2;

        while(count <= n){
            f2 = f0 + f1;
            f0 = f1;
            f1 = f2;
            count ++;
        }

        return f2;
    }
};
