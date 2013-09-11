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
    vector<vector<int> > get_combinations(int start, int end, int k, vector<int> pre_combination){
        vector<vector<int> > combinations;  
        
        if(k == 0){
            if(pre_combination.size() != 0)
                combinations.push_back(pre_combination);
            
            return combinations;
        }

        if(end - start + 1 < k)
            return combinations;

        // case 1: not include start
        combinations = get_combinations(start + 1, end, k, pre_combination);

        // case 2: include start
        pre_combination.push_back(start);
        vector<vector<int> > tmp = get_combinations(start + 1, end, k - 1, pre_combination);
        combinations.insert(combinations.end(), tmp.begin(), tmp.end());

        return combinations;
    }

public:
    vector<vector<int> > combine(int n, int k) {
        vector<int> tmp;

        return get_combinations(1, n, k, tmp);
    }
};
