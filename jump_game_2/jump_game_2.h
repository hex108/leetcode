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
    /* 'record[i]' records the smallest index that could reach last index in
     * i steps. We nee to maintain a property for 'record':
     * record[0] > record[1] > ... > record[max_steps].
     * e.g. if record[0 ... 3] = {8, 7, 6, 5} and max_steps = 4, then we find
     * A[4] = 8, then we set A[0] = 4, and max_steps = 0 becuase we are 
     * searching backward, if it could reach A[5] or A[6], it must could reach
     * A[4], there will be short steps if we choose reaching last index through
     * A[4], so the steps after A[4] is not useful.
     */
    vector<int> record;
    int max_steps;

    void init(int n){
        record.clear();
        record.resize(n, -1);

        record[0] = n - 1;
        max_steps = 0;
    }

    int jump_at(int A[], int start){
        int max_jump = start + A[start]; 
        
        int low = 0, high = max_steps;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(record[mid] > max_jump)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low;
    }

public:
    int jump(int A[], int n) {
        init(n);

        int steps = 0;
        for(int i = n - 2; i >= 0; i --){
            steps = jump_at(A, i);
            // could not reach the last index.
            if(steps > max_steps)
                continue;

            // include the start step from A[i].
            steps ++;  
            record[steps] = i;
            max_steps = steps;
        }

        return steps;
    }
};
