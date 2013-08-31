/* Notes:
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <string.h>

#include "test.h"
using namespace std;

class Solution {
    void fill_no_wild_len(vector<int> &no_wild_len, const char *p, int len){
        no_wild_len.resize(len);

        int count = 0;
        bool has_star = false;
        for(int i = len - 1; i >= 0; i --){
            if(p[i] != '*'){
                if(!has_star)
                    count ++;
                else
                    has_star = false;
            }else{
                has_star = true;
            }
            no_wild_len[i] = count;
        }
    }

    void add_to_be_searched(vector<int> &v, int index, set<int> &has_searched){
        if(has_searched.count(index))
            return;

        has_searched.insert(index);
        v.push_back(index);
    }
public:
    bool isMatch(const char *s, const char *p) {
        if(*p == 0)
            return *s == 0;

        /* no_wild_len[index] records how many normal-character from index to 
         * end in 'p'.
         */
        vector<int> no_wild_len;  
        fill_no_wild_len(no_wild_len, p, strlen(p));

        int len_s = strlen(s);

        // From which index in 'p'
        vector<int> to_be_matched; 
        to_be_matched.push_back(0);

        while(*s && to_be_matched.size() ){
            vector<int> tmp;
            set<int> has_searched;
            for(size_t i = 0; i < to_be_matched.size(); i ++){
                int index = to_be_matched[i];
                if(no_wild_len[index] > len_s)
                    continue;

                if(p[index] == '.' || p[index] == *s)
                    add_to_be_searched(tmp, index + 1, has_searched);
                else if(p[index] == '*'){
                    // case 1 : the preceding element matches.
                    to_be_matched.push_back(index - 1);

                    // case 2 : the preceding element does not match.
                    to_be_matched.push_back(index + 1);
                }
                
                // e.g. aab and c*a*b, then we need skip 'c*'.
                if(p[index] != 0 && p[index + 1] == '*'){
                    to_be_matched.push_back(index + 2);
                }
            }
            to_be_matched.swap(tmp);
            s ++;
            len_s --;
        }

        if(*s == 0){
            for(size_t i = 0; i < to_be_matched.size(); i ++){
                int index = to_be_matched[i];

                if(p[index] == 0 || no_wild_len[index] == 0)
                    return true;
            }
        }
        
        return false;
    }
};
