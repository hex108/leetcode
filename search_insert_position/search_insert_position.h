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
    int searchInsert(int A[], int n, int target) {
        int low = 0, high = n - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            
            if(A[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low;
    }
};
