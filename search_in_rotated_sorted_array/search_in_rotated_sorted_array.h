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
    int binary_search(int A[], int low, int high, int target){
        while(low <= high){
            int mid = low + (high - low) / 2;

            if(A[mid] == target)
                return mid;
            else if(A[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }

public:
    // assume it is an ascending array
    int search(int A[], int n, int target) {
        int low = 0, high = n - 1;

        while(low <= high){
            if(A[low] <= A[high]) // It will be satified at the end at least.
                return binary_search(A, low, high, target);
            
            int mid = low + (high - low) / 2;
            if(A[mid] == target)
                return mid;
            else if(A[mid] < A[low]){ 
            // [low, mid] is not ascending, [mid, high] is ascending
                if(target > A[mid] && target <= A[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }else{
            // [low, mid] is ascending, [mid, high] is not ascending
                if(target >= A[low] && target < A[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }

        return -1;
    }
};
