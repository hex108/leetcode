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
    vector<string> transform(string start, unordered_set<string> &dict,
            set<string> &has_searhed){
        vector<string> transformed_set;

        for(string::size_type index = 0; index < start.size(); index ++){
            for(int c = 'a'; c <= 'z'; c++){
                if(start[index] == c)
                    continue;

                string tmp = start;
                tmp[index] = c;

                if(dict.count(tmp) && !has_searhed.count(tmp)){
                    transformed_set.push_back(tmp);
                    has_searhed.insert(tmp);
                }
            }
        }

        return transformed_set;
    }

public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        vector<string> search_set;
        set<string> has_searhed;
        
        search_set.push_back(start);
        int search_times = 1;

        while(!search_set.empty()){
            vector<string> next_search_set;
            vector<string>::iterator iter;
            for(iter = search_set.begin(); iter != search_set.end(); iter ++){
                if(*iter == end)
                    return search_times;

                vector<string> tmp = transform(*iter, dict, has_searhed);
                next_search_set.insert(next_search_set.end(), tmp.begin(), tmp.end());
            }

            search_times ++;
            search_set.swap(next_search_set);
        }

        return 0;
    }
};
