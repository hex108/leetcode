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
    // 'min_index' records the minimum index that could reach the last index.
    int min_index;

    bool can_jum(int A[], int n, int start, vector<bool> &record){
        int max_jum = A[start]; 
        
        if(start + max_jum >= min_index){
            min_index = start;

            return true;
        }else
            return false;
    }

public:
    bool canJump(int A[], int n) {
        vector<bool> record(n, false); 
        record[n - 1] = true;
        
        min_index = n - 1;

        for(int i = n - 2; i >= 0; i --)
            record[i] = can_jum(A, n, i, record);

        return record[0];
    }
};

/* Time Limit Exceeded
class Solution {
    bool can_jum(int A[], int n, int start, vector<bool> &record){
        int max_jum = A[start]; 
        
        for(int i = 1; i <= max_jum; i ++){
            int jump_point = start + i;
            if(jump_point >= n)
                break;

            if(record[jump_point] == true)
                return true;
        }

        return false;
    }

public:
    bool canJump(int A[], int n) {
        vector<bool> record(n, false); 
        record[n - 1] = true;

        for(int i = n - 2; i >= 0; i --)
            record[i] = can_jum(A, n, i, record);  

        return record[0];
    }
};
*/
