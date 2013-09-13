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
    size_t count_of_str; // the count of strings in 'L'
    size_t element_size; // the size of each string in 'L'
    map<string, int> record; // record the number of each string in 'L'

    void init(vector<string> &L){
        count_of_str = 0;
        record.clear();
        
        for(size_t i = 0; i < L.size(); i ++){
            count_of_str ++;
            string s = L[i];
            record[s] ++;
        }
    }

    bool is_valid(string S, vector<string> &L){
        if(L.size() == 0)
            return false;

        size_t size_L = L.size() * L[0].size();
        size_t size_S = S.size();
        if(size_S < size_L)
            return false;

        return true;
    }

    vector<int> find_substr(string S, size_t start, vector<string> L){
        size_t count = 0;
        map<string, int> tmp_record = record;

        // record starting indices satifies conditions in this part
        vector<int> indexes;  

        size_t size_S = S.size();
        for(size_t i = start; i < size_S;){
            /* remain characters in S are not enough to contain remain strings 
             * in L.
             */
            if(size_S - i + 1 < (count_of_str - count) * element_size)
                break;

            string str =  S.substr(i, element_size);

            /* If current string is not in L, restart from 'i + element_size' 
             * to search.
             */
            if(tmp_record.count(str) == 0){
                tmp_record = record;
                start = i + element_size;
                i = start;
                count = 0;

                continue;
            }

            /* advance the start, continue to search whether 
             * [start + element_size, ?] will satify the condition.
             */
            if(tmp_record[str] < 1){
                string start_str = S.substr(start, element_size);
                tmp_record[start_str] ++; 
                start += element_size;
                count --;

                continue;
            }
           
            tmp_record[str] --;
            count ++;
            i += element_size;
            
            /* [start, i + element_size - 1] in S satifies the condition.
             * Advance the start, check whether [start + element_size, 
             * i + 2 * element_size - 1] will satify the condition.
             */
            if(count == count_of_str){
                indexes.push_back(start);

                string start_str = S.substr(start, element_size);
                tmp_record[start_str] ++; 
                start += element_size;
                count --;
            }
        }

        return indexes;
    }

public:
    vector<int> findSubstring(string S, vector<string> &L) {
        init(L);
        
        vector<int> indexes;

        if(is_valid(S, L) == false)
            return indexes;

        /* It is an optimization compared with the normal way.
         * In the normal way, we check 0 ~ S.size()-1 of S one by one.
         * Now, we divide it to 'element_size' parts: 
         * 0,                element_size,     2 * element_size ...
         * 1,                element_size + 1, 2 * element_size + 1 ...
         * 2,                element_size + 2, 2 * element_size + 2 ...
         * ...
         * element_size - 1, 2 * element_size - 1, 3 * element_size - 1 ...
         *
         * For dealing with each part, see function 'find_substr' for deatails.
         */
        element_size = L[0].size();
        for(size_t i = 0; i < element_size; i ++){
            vector<int> partial_indexes = find_substr(S, i , L);

            indexes.insert(indexes.end(), partial_indexes.begin(), partial_indexes.end());
        }

        return indexes;
    }
};

/* time out
class Solution {
    size_t count_of_str;
    map<string, int> record;

    void init(vector<string> &L){
        count_of_str = 0;
        record.clear();
        
        for(size_t i = 0; i < L.size(); i ++){
            count_of_str ++;
            string s = L[i];
            record[s] ++;
        }
    }

    bool contains(string S, size_t start, vector<string> L){
        size_t element_size = L[0].size();
        size_t count = count_of_str;
        map<string, int> tmp_record = record;

        while(count){
            string str =  S.substr(start, element_size);

            if(tmp_record[str] < 1)
                return false;
           
            tmp_record[str] --;
            start += element_size;
            count --;
        }

        return true;
    }

public:
    vector<int> findSubstring(string S, vector<string> &L) {
        init(L);
        
        vector<int> indexes;
        if(L.size() == 0)
            return indexes;

        size_t size_L = L.size() * L[0].size();
        size_t size_S = S.size();
        for(size_t i = 0; size_S - i >= size_L; i ++){
            if(contains(S, i, L))
                indexes.push_back(i);
        }

        return indexes;
    }
};
*/

/* time out
class Solution {
    // Pre: L is sorted using sort.
    //      size_S - start >= size_L      
    bool contains(string S, size_t start, vector<string> L){
        size_t element_size = L[0].size();

        while(L.size() != 0){
            vector<string>::iterator it;
            it = b_search(L.begin(), L.end(), S.substr(start, element_size));
            if(it == L.end())
                return false;
           
            L.erase(it, it + 1);
            start += element_size;
        }

        return true;
    }

    template<class Iterator, class T>
    Iterator b_search(Iterator begin, Iterator end, T s){
        Iterator tmp_end = end;
        end --;
        while(begin <= end){
            Iterator mid = begin + (end - begin) / 2;
            if(*mid == s)
                return mid;
            else if(*mid < s)
                begin = mid + 1;
            else
                end = mid - 1;
        }

        return tmp_end; 
    }

public:
    vector<int> findSubstring(string S, vector<string> &L) {
        sort(L.begin(), L.end());  
        
        vector<int> indexes;
        if(L.size() == 0)
            return indexes;

        size_t size_L = L.size() * L[0].size();
        size_t size_S = S.size();
        for(size_t i = 0; size_S - i >= size_L; i ++){
            if(contains(S, i, L))
                indexes.push_back(i);
        }

        return indexes;
    }
};
*/
