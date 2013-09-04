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
    void swap(vector<int> &num, int i, int j){
        int tmp = num[i];
        num[i] = num[j];
        num[j] = tmp;
    }

    /* [low, high] is non-descending.
     * return the smallest index which num[index] > target.
     */
    int binary_search(vector<int> &num, int low, int high, int target){
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(num[mid] <= target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low;
    }

public:
    void nextPermutation(vector<int> &num) {
        if(num.size() <= 1)
            return;

        int end = num.size() - 1;
        /* 'max' record the min number of [i + 1, end].
         * 'start_index' records the largest index which could be exchanged with
         * its following number that is less than it. Then we could conclude that 
         * [start_index + 1, end] is non-descending.
         */
        int max = num[end], start_index;
        for(start_index = end - 1; start_index >= 0; start_index --){
            int n = num[start_index];
            if(max <= n)
                max = n;
            else
                break;
        }
        
        // num is non-descending.
        if(start_index < 0){
            reverse(num.begin(), num.end());
        }else{
            reverse(num.begin() + start_index + 1, num.end());

            int swap_index = binary_search(num, start_index + 1, end, num[start_index]);
            swap(num, start_index, swap_index);
        }
    }
};
