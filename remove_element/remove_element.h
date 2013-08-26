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
    int removeElement(int A[], int n, int elem) {
        int total = n - 1;

        for(int i = 0; i <= total; i ++){
            if(A[i] != elem)
                continue;

            while(total >= i && A[total] == elem)
                total --;
            
            if(total >= i){
                A[i] = A[total];
                total --;
            }
        }

        return total + 1;
    }
};
