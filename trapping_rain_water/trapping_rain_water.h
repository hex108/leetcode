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
    /* To solve the problem, we could find all containers which satifies:
     * in container [left_index, right_index], any index x between left_index
     * and right_index satisfies: A[x] <= A[left_index] && A[x] <= A[right_index].
     * For each container, we calculate its capacity.
     */
    int trap(int A[], int n) {
        if(n <= 1)
            return 0;

        /* Using max_elevation is just an optimization. According to it, we
         * could judge whether there is an right_index satisfying 
         * A[right_index] <= A[left_elevation]. Then we could know the 
         * container's shape and deal with it differently.
         */
        vector<int> max_elevation(n, 0); // From right to left.
        int max = 0;
        for(int i = n - 1; i >= 0; i --){
            if(A[i] > max)
                max = A[i];
            max_elevation[i] = max;
        }

        if(max == 0)
            return 0;

        int left = 0;
        while(A[left] == 0)
            left ++;

        int water = 0; // 'water' records how much is trapped rain water.
        for(int i = left + 1; i < n ; i ++){
            int left_elevation = A[left];
            int need_subtracted = 0;

            if(max_elevation[i] > left_elevation){
                // container where right elevation is higher.
                while(A[i] < left_elevation){
                    need_subtracted += A[i];
                    i ++;
                }
                water += (i - left - 1) * left_elevation - need_subtracted;
            }else{
                // container where left elevation is higher.
                int tmp_max_elevation = max_elevation[i];
                while(A[i] != tmp_max_elevation){
                    need_subtracted += A[i];
                    i ++;
                }
                water += (i - left - 1) * tmp_max_elevation - need_subtracted;
            }

            left = i;
        }

        return water;
    }
};
