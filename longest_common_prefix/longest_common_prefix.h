/* Notes: Compare less times.
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
using namespace std;

class Solution {
    int get_minimum_len(vector<string> &strs){
        int min = strs[0].size();

        for(size_t i = 1; i < strs.size(); i ++){
            int size = strs[i].size();
            if(size < min)
                min = size;
        }

        return min;
    }
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.size() == 0)
            return "";

        int longest = 0;
        int min_len = get_minimum_len(strs);
        size_t longest_step = (strs.size() + 1) / 2;

        while(1){    
            if(longest >= min_len)
                break;

            for(size_t step = 1; step <= longest_step; step = step * 2){
                //cout << "step : " << step << endl;
                for(size_t i = 0; i + step < strs.size(); i += 2 * step){
                    //cout << "i : " << i << endl;
                    if(strs[i][longest] != strs[i + step][longest])
                        return strs[0].substr(0, longest);
                }
            }
            longest ++;
        }

        return strs[0].substr(0, longest);
    }
};
