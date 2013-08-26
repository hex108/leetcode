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
        int allowed_times = 2; 
        int total = 0, cur = 0;

        while(cur < n){
            int i, next;

            for(next = cur, i = 1; next < n && i <= allowed_times; next ++, i ++){
                if(A[next] == A[cur])
                    A[total ++] = A[next];
                else
                    break;
            }

            while(next < n && A[next] == A[cur])
                next ++;

            cur = next;
        }

        return total;
    }
};
