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
public:
    int firstMissingPositive(int A[], int n) {
        if(n <= 0)
            return 1;

        for(int i = 0; i < n; i ++){
            int tmp = A[i];
            if(tmp <= 0 || tmp >= n)
                continue;

            if(tmp != i + 1 && A[tmp - 1] != tmp){
                swap(A[i], A[tmp - 1]);

                if(tmp > i)
                    i --;
            }
        }

        for(int i = 0; i < n; i ++){
            if(A[i] != i + 1)
                return i + 1;    
        }
        
        return n + 1;
    }
};
