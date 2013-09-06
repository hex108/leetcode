/* Notes:
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <deque>

#include "test.h"
using namespace std;

class Solution {
    // 'letters_in_T' records number of each same letter in T.
    map<char, int> letters_in_T;
    // 'location' records lastest location of T's letters in S.
    map<char, deque<int> > location;
    /* 'current_start' records the start index of current window.
     * It is a small optimization. If the start index of the current window
     * have not been changed, we could use it for every call 'get_start'.
     */
    int current_start;

    void init(string T){
        letters_in_T.clear();
        location.clear();
        current_start = -1;

        size_t size = T.size();
        for(size_t i = 0; i < size; i ++){
            char c = T[i];
            letters_in_T[c] ++;
        }
    }

    void update_location(char c, int index){
        map<char, deque<int> >::iterator it = location.find(c);

        int min = it->second.front();
        if(min == current_start)
            current_start = -1;

        it->second.pop_front();
        it->second.push_back(index);
    }

    int get_start(){
        if(current_start != -1)
            return current_start;
    
        current_start = location.begin()->second.front();
        map<char, deque<int> >::iterator it;
        for(it = location.begin(); it != location.end(); it ++){
           int index = it->second.front(); 
           if(index < current_start)
               current_start = index;
        }

        return current_start;
    }

public:
    string minWindow(string S, string T) {
        if(S.size() < T.size())
            return "";

        init(T);

        int start = -1, min_size = S.size() + 1;
        int target = T.size();
        int n = 0; // records how many T's letters has been found in S.

        for(size_t i = 0; i < S.size(); i ++){
            char c = S[i];
            if(letters_in_T.count(c) == 0)
                continue;

            if(letters_in_T[c] >= 1){
                location[c].push_back(i);
                letters_in_T[c] --;
                n ++;
            }else
                update_location(c, i);

            if(n == target){
                int current_start = get_start();
                int current_size = (int)i - current_start + 1;
                if(current_size < min_size){
                    start = current_start;
                    min_size = current_size;
                }
            }
        }

        if(start != -1)
            return S.substr(start, min_size);
        else
            return "";
    }
};
