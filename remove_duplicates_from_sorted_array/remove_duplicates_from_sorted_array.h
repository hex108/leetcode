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
    int removeDuplicates(int A[], int n) {
        int total = 0;

        int cur = 0, next;
        while(cur < n){
            A[total ++] = A[cur];

            next = cur + 1;
            while(next < n && A[next] == A[cur])
                next ++;

            cur = next;
        }

        return total;
    }
};
