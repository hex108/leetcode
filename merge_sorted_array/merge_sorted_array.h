/* Notes: The important thing is that identify the sorted order of A and B.
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
    static bool greater_equal(int a, int b){
        return a >= b;
    }

    static bool less_than(int a, int b){
        return a < b;
    }
public:
    void merge(int A[], int m, int B[], int n) {
        if(m == 0){
            for(int i = 0; i < n; i ++)
                A[i] = B[i];
            return;
        }else if(n == 0){
            return;
        }

        int a_start = A[0], a_end = A[m - 1];
        int b_start = B[0], b_end = B[n - 1];
        int total_end = m + n - 1;
        bool (*compare)(int a, int b);

        if(a_start > a_end)
            compare = less_than;
        else
            compare = greater_equal;

        if((a_start > a_end && b_start > b_end) || (a_start <= a_end && b_start <= b_end)){
            int i = m - 1, j = n - 1;
            while( i >= 0 && j >= 0){
                if(compare(A[i], B[j])){
                    A[total_end] = A[i --];
                }else{
                    A[total_end] = B[j --];
                }
                total_end --;
            }
            while(j >= 0){
                A[total_end --] = B[j --];
            }
        }else{
            int i = m - 1, j = 0;
            while( i >= 0 && j <= n - 1){
                if(compare(A[i], B[j])){
                    A[total_end] = A[i --];
                }else{
                    A[total_end] = B[j ++];
                }
                total_end --;
            }
            while(j <= n - 1){
                A[total_end --] = B[j ++];
            }
        }
    }
};
