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
public:
    int maxSubArray(int A[], int n) {
        int max_sum = INT_MIN;

        int cur_sum = 0;
        bool first_num = true;
        for(int i = 0; i < n; i ++){
            int num = A[i]; 
            if(num < 0){
                if(first_num){ 
                    max_sum = max(num, max_sum); 
                }else{
                    max_sum = max(max_sum, cur_sum);

                    cur_sum += num;
                    if(cur_sum <= 0){
                        cur_sum = 0;
                        first_num = true;
                    }
                }
            }else{
                cur_sum += num;
                first_num = false;
            }
        }

        if(first_num == false)
            max_sum = max(cur_sum, max_sum);

        return max_sum;
    }
};
