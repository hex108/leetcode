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
    int find_low(int A[], int n, int target){
        int low = 0, high = n - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(A[mid] >= target)
                high = mid - 1;
            else
                low = mid + 1;
        }

        //cout << "low = " << low << ", high = " << high << endl;
        if(low < 0 || A[low] != target)
            return -1;
        else
            return low;
    }

    int find_high(int A[], int n, int target){
        int low = 0, high = n - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(A[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }

        //cout << "low = " << low << ", high = " << high << endl;
        if(high < 0 || A[high] != target)
            return -1;
        else
            return high;
    }

public:
    vector<int> searchRange(int A[], int n, int target) {
        int low = find_low(A, n, target);
        int high = find_high(A, n, target);
        vector<int> range;

        range.push_back(low);
        range.push_back(high);

        return range;
    }
};
