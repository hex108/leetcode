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
    void swap(vector<int> &num, int i, int j){
        int tmp = num[i];
        num[i] = num[j];
        num[j] = tmp;
    }
    
    void add_start(vector<vector<int> > &permutations, int start){
        vector<vector<int> >::iterator iter;
        for(iter = permutations.begin(); iter != permutations.end(); iter ++){
            iter->push_back(start);
        }
    }

    vector<vector<int> > do_permute(vector<int> &num, int start, int end){
        vector<vector<int> > permutations;

        if(end <= start){
            if(end == start){
                vector<int> tmp(1, num[start]);
                permutations.push_back(tmp);
            }
            return permutations;
        }

        for(int i = start; i <= end; i ++){
            swap(num, start, i);

            vector<vector<int> > tmp = do_permute(num, start + 1, end);
            add_start(tmp, num[start]);

            swap(num, start, i);

            permutations.insert(permutations.end(), tmp.begin(), tmp.end());
        }

        return permutations;
    }
public:
    vector<vector<int> > permute(vector<int> &num) {
        return do_permute(num, 0, num.size() - 1);
    }
};
