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
    /* 'current' is current index of 'num'.
     * 'pre_combination' is previous combination. 
     */
    vector<vector<int> > get_combination(vector<int> &num, size_t current,
                                vector<int> pre_combination, int target){
        vector<vector<int> > combinations;

        if(target == 0){
            if(pre_combination.size() != 0)
                combinations.push_back(pre_combination);

            return combinations;
        }

        if(current >= num.size() || target < num[current])
            return combinations;

        int n = num[current];
        /* combinations might contains zero or one time 'n'.
         * But we need handle dumplicates.
         */
        size_t end = current + 1;
        while(end < num.size() && num[end] == n)
            end ++;

        int count = end - current;
        // contains 'n' 0~count times.
        for(int i = 0; i <= count; i ++){
            vector<vector<int> > ret;
            ret = get_combination(num, end, pre_combination, target);
            combinations.insert(combinations.end(), ret.begin(), ret.end());

            if(target < n)
                break;

            target -= n;
            pre_combination.push_back(n);
        }

        return combinations;
    }

public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // sort and unique the num.
        sort(num.begin(), num.end());

        vector<int> tmp;
        return get_combination(num, 0, tmp, target);
    }
};
