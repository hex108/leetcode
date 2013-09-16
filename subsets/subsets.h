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

#include "test.h"
using namespace std;

class Solution {
    vector<vector<int> > get_sets(vector<int> &S, int start, int end, 
                                  vector<int> pre_record){
        vector<vector<int> > sets;  

        if(start > end){
            sets.push_back(pre_record);
            return sets;
        }
        
        // do not include S[start] 
        sets = get_sets(S, start + 1, end, pre_record); 

        // include S[start]
        pre_record.push_back(S[start]);
        vector<vector<int> > tmp = get_sets(S, start + 1, end, pre_record);
        sets.insert(sets.end(), tmp.begin(), tmp.end());

        return sets;
    }

public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<int> pre_record;

        sort(S.begin(), S.end());

        return get_sets(S, 0, S.size() - 1, pre_record);
    }
};
