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
    /* sort A[start ... end] to two parts: A[0 ... i - 1] do not contain color2, 
     * A[i ... end] do not contain color1.
     * Note: there might be other colors.
     */
    int sort_two_colors(int A[], int start, int end, int color1, int color2){
        int i, j;
        for(i = start, j = end; i <= j ; i ++, j --){
            // until A[i] is not color1
            while(i <= j && A[i] == color1)
                i ++;

            // until A[j] is not color2
            while(j >= i && A[j] == color2)
                j --;

            /* it's '>=' not '>' because A[i] might be not either color1 
             * or color2. 
             */
            if(i >= j)
                break;

            swap(A[i], A[j]);
        }

        return i;
    }
public:
    void sortColors(int A[], int n) {
        /* sort A[] to two parts: A[0 ... i - 1] contains red and white, 
         * A[i ... n - 1] contains white and blue.
         */
        int i = sort_two_colors(A, 0, n - 1, 0, 2);

        /* sort A[0 ... i - 1] to two parts: left part only contains red,
         * right part only contails while.
         */
        sort_two_colors(A, 0, i - 1, 0, 1); 

        /* sort A[0 ... i - 1] to two parts: left part only contains white,
         * right part only contails blue.
         */
        sort_two_colors(A, i, n - 1, 1, 2);
    }
};
