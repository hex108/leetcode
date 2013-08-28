/* Notes: I do not know why linear search does not exceed the time limit.
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
    bool search(int A[], int n, int target) {
        for(int i = 0; i < n ; i ++){
            if(A[i] == target)
                return true;
        }
        
        return false;
    }
};

/* Although the following method works, linear search works too!!! It is more simple.
 */
/*
class Solution {
    bool binary_search(int A[], int low, int high, int target){
        while(low <= high){
            int mid = low + (high - low) / 2;

            if(A[mid] == target)
                return true;
            else if(A[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return false;
    }

public:
    bool search(int A[], int n, int target) {
        int low = 0, high = n - 1;

        while(low <= high){
            if(A[low] < A[high])
                return binary_search(A, low, high, target);
            
            int mid = low + (high - low) / 2;
            if(A[mid] == target)
                return true;
            
            if(A[mid] == A[low]){
                if(A[mid] == A[high]){
                    int tmp = low + 1;
                    while(tmp < mid){
                        if(A[tmp] != A[mid])
                            break;
                        tmp ++;
                    }
                    if(tmp == mid) // A[low...mid] are the same number
                        low = mid + 1;
                    else // A[mid...high] are the same number
                        high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }else if(A[mid] < A[low]){ 
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

        return false;
    }
};
*/
