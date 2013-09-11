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
    /* 'current' is current index of candidates.
     * 'pre_combination' is previous combination. 
     */
    vector<vector<int> > get_combination(vector<int> &candidates, size_t current,
                                vector<int> pre_combination, int target){
        vector<vector<int> > combinations;

        if(target == 0){
            if(pre_combination.size() != 0)
                combinations.push_back(pre_combination);

            return combinations;
        }

        if(current >= candidates.size() || target < candidates[current])
            return combinations;

        int n = candidates[current];

        // combinations might contains zero or more times 'n'.
        while(1){
            vector<vector<int> > ret;
            ret = get_combination(candidates, current + 1, pre_combination, target);
            combinations.insert(combinations.end(), ret.begin(), ret.end());

            if(target < n)
                return combinations;

            target -= n;
            pre_combination.push_back(n);
        }
    }

public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // sort and unique the candidates.
        sort(candidates.begin(), candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

        vector<int> tmp;
        return get_combination(candidates, 0, tmp, target);
    }
};
