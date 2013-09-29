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
    multimap<string, string> reverse_transform;

    vector<string> transform(string start, unordered_set<string> &dict, 
            set<string> &has_searhed, set<string> &searhed_in_same_loop){
        vector<string> transformed_set;

        for(string::size_type index = 0; index < start.size(); index ++){
            for(int c = 'a'; c <= 'z'; c++){
                if(start[index] == c)
                    continue;

                string tmp = start;
                tmp[index] = c;

                if(dict.count(tmp) 
                    && (!has_searhed.count(tmp) || searhed_in_same_loop.count(tmp))){
                    transformed_set.push_back(tmp);
                    has_searhed.insert(tmp);
                    searhed_in_same_loop.insert(tmp);
                    reverse_transform.insert(pair<string, string>(tmp, start));
                }
            }
        }

        return transformed_set;
    }

    void buildLadders(string start, string end, unordered_set<string> &dict){
        vector<string> search_set;
        search_set.push_back(start);

        set<string> has_searhed;

        while(!search_set.empty()){
            vector<string> next_search_set;
            set<string> searhed_in_same_loop;

            vector<string>::iterator iter;
            for(iter = search_set.begin(); iter != search_set.end(); iter ++){
                if(*iter == end)
                    return;

                vector<string> tmp = transform(*iter, dict, has_searhed, searhed_in_same_loop);
                next_search_set.insert(next_search_set.end(), tmp.begin(), tmp.end());
            }

            search_set.swap(next_search_set);
            sort(search_set.begin(), search_set.end());
            search_set.erase(unique(search_set.begin(), search_set.end()), search_set.end());
        }
    }

    void addWordToLadders(vector<vector<string> > &ladders, string word){
        vector<vector<string> >::iterator iter;
        for(iter = ladders.begin(); iter != ladders.end(); iter ++){
            iter->push_back(word);
        }
    }

    vector<vector<string> > reverseLadder(string start, string end){
        vector<vector<string> > ladders;
        if(start == end){
            vector<string> tmp;
            tmp.push_back(start);
            ladders.push_back(tmp);

            return ladders;
        }

        multimap<string, string>::iterator iter;
        for(iter = reverse_transform.lower_bound(end); iter != reverse_transform.upper_bound(end); iter ++){
            vector<vector<string> > tmp = reverseLadder(start, iter->second);
            ladders.insert(ladders.end(), tmp.begin(), tmp.end());          
        }

        addWordToLadders(ladders, end);

        return ladders;
    }

public:
    vector<vector<string> > findLadders(string start, string end, 
            unordered_set<string> &dict) {
        unordered_set<string> modified_dict = dict;
        modified_dict.insert(end);

        reverse_transform.clear();

        buildLadders(start, end, modified_dict);

        return reverseLadder(start, end);
    }
};
