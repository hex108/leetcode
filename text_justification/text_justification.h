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
    size_t get_one_line(vector<string> &words, size_t start, int L){
        while(start < words.size() && (int)words[start].size() <= L){
            L = L - words[start].size() - 1;
            start ++;
        }

        return start;
    }

    string full_justify_one_line(vector<string> &words, size_t start, 
                                 size_t end, int L){
        int remain = L;
        for(size_t i = start; i < end; i ++)
            remain -= words[i].size();

        int n_space = end - start - 1;
        if(n_space == 0)
            return words[start] + string(L - words[start].size(), ' ');

        int average_spaces = remain / n_space;
        int remain_sapces = remain % n_space;

        string justified_str;
        string spaces(average_spaces + 1, ' ');
        // first 'remain_sapces' space will contain 'average_spaces + 1' spaces.
        for(size_t i = start; i < start + remain_sapces; i ++)
            justified_str.append(words[i] + spaces); 

        // remain space will contain 'average_spaces' spaces.
        spaces.resize(average_spaces);
        for(size_t i = start + remain_sapces; i < end - 1; i ++)
            justified_str.append(words[i] + spaces); 
        
        justified_str.append(words[end - 1]);

        return justified_str;
    }

    string full_justify_last_line(vector<string> &words, size_t start, 
                                  size_t end, int L){
        string justified_str="";
        int remain = L;  
        
        justified_str.append(words[start]);
        remain -= words[start].size();
        for(size_t i = start + 1; i < end; i ++){
            remain -= words[i].size() + 1;
            justified_str.append(" " + words[i]);
        }

        justified_str.append(string(remain, ' '));

        return justified_str;
    }

public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> justified_strs;

        size_t start, end;
        for(start = 0; start < words.size(); start = end){
            // line will contain [start, end)
            end = get_one_line(words, start, L);

            if(end < words.size()){
                string str = full_justify_one_line(words, start, end, L); 
                justified_strs.push_back(str);
            }else{
                string str = full_justify_last_line(words, start, end, L);
                justified_strs.push_back(str);

                break;
            }
        }

        return justified_strs;
    }
};
