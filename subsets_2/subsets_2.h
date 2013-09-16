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
        
        int cur_num = S[start];
        int count = get_count_of_target(S, start, end, cur_num);

        // include S[start]: 0/1/2/3 ... count times
        for(int i = 0; i <= count; i ++){
            vector<vector<int> > tmp = get_sets(S, start + count, end, pre_record);
            sets.insert(sets.end(), tmp.begin(), tmp.end());

            pre_record.push_back(cur_num);
        }

        return sets;
    }

    // target is S[start].
    int get_count_of_target(vector<int> &S, int start, int end, int target){
        int count = 0;
        for(int i = start; i <= end; i ++){
            if(S[i] != target)
                break;
            count ++;
        }

        return count;
    }

public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<int> pre_record;

        sort(S.begin(), S.end());

        return get_sets(S, 0, S.size() - 1, pre_record);
    }
};
