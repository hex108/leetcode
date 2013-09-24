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
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> anagram_strs;

        map<string, int> record;
        set<int> need_add; // avoid push_back one string many times.

        for(size_t i = 0; i < strs.size(); i ++){
            string s = strs[i]; 
            sort(s.begin(), s.end());

            if(record.count(s)){
                anagram_strs.push_back(strs[i]);
                /* If we push_back strs[record[s]] now, it will be push_back-ed
                 * every time we find same anagrams. So we just use 'need_add'
                 * to record it.
                 */
                need_add.insert(record[s]);
            }else
                record[s] = i;
        }

        set<int>::iterator it;
        for(it = need_add.begin(); it != need_add.end(); it ++)
            anagram_strs.push_back(strs[*it]);

        return anagram_strs;
    }
};

/* Time Limit Exceed.
class Solution {
    vector<map<char, int> > map_record;
    vector<bool> has_been_added;
    vector<bool> has_record;

    void init(size_t n){
        has_been_added.clear();
        has_been_added.resize(n, false);

        has_record.clear();
        has_record.resize(n, false);

        map_record.clear();
        map<char, int> tmp;
        map_record.resize(n, tmp);
    }

    void set_record(const string &s, int index, map<char, int> &record){
        if(has_record[index])
            record = map_record[index];
        else{
            do_set_record(s, record);
            map_record[index] = record;
            has_record[index] = true;
        }
    }

    void do_set_record(const string &s, map<char, int> &record){
        for(size_t i = 0; i < s.size(); i ++){
            char c = s[i];
            record[c] ++;
        }
    }

    bool is_anagram(vector<string> &strs, int index1, int index2){
        if(strs[index1].size() != strs[index2].size())
            return false;

        map<char, int> record1, record2;
        set_record(strs[index1], index1, record1);
        set_record(strs[index2], index2, record2);
        
        if(record1.size() != record2.size())
            return false;

        map<char, int>::iterator it;
        for(it = record1.begin(); it != record1.end(); it ++){
            char c = it->first; 
            if(record2.count(c) == 0 || record2[c] != it->second)
                return false;
        }

        return true;
    }

public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> anagram_strs;    

        init(strs.size());

        int end = strs.size() - 1;
        for(int i = 0; i < end; i ++){
            if(has_been_added[i] == true)
                continue;

            bool found = false;
            for(int j = i + 1; j <= end; j ++){
                if(is_anagram(strs, i, j)){
                    has_been_added[j] = true;
                    anagram_strs.push_back(strs[j]);
                    found = true;
                }
            }

            if(found == true)
                anagram_strs.push_back(strs[i]);
        } 
        
        return anagram_strs;
    }
};
*/
