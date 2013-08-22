/* Notes: Although record is used, the time exceeds the limit. We need to 
 *        find another way.
 *        Use breath first searh. And we need implement it effectively.
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
using namespace std;


class Solution {
    bool isPalindrome(string s, size_t start, size_t end){
        for(size_t i = start, j = end; i < j; i ++, j --){
            if(s[i] != s[j])
                return false;
        }

        return true;
    }

public:
    int minCut(string s){
        size_t len = s.size();

        if(len == 0)
            return 0;

        vector<int> record(len, -1);
        vector<int> need_cut;
        need_cut.push_back(0);
        
        int n = 0;
        while(!need_cut.empty()){
            vector<int> tmp;
            for(size_t i = 0; i < need_cut.size(); i ++){
                if(isPalindrome(s, need_cut[i], len - 1)){
                    return n; 
                }
            }

            for(size_t i = 0; i < need_cut.size(); i ++){
                size_t start = need_cut[i];
                for(size_t j = start; j < len - 1; j ++){
                    if(record[j + 1] != 0 && isPalindrome(s, start, j)){
                        tmp.push_back(j + 1);
                        record[j + 1] = 0;
                    }
                }
            }
            n ++;
            need_cut.swap(tmp);
        }

        return -1;
    }
};

/* 2. Time out.
 */
/*
class Solution {
    vector<vector<int> > record;

    bool isPalindrome(string s, size_t start, size_t end){
        for(size_t i = start, j = end; i < j; i ++, j --){
            if(s[i] != s[j])
                return false;
        }

        return true;
    }

    int getMinCut(string s, size_t start, size_t end){
        if(record[start][end] != -1)
            return record[start][end];

        if(isPalindrome(s, start, end)){
            record[start][end] = 0;

            return 0;
        }

        int min = end - start;
        for(size_t i = start; i <= end - 1; i ++){
            if(isPalindrome(s, start, i)){
                int n = getMinCut(s, i + 1, end) + 1;

                if(n < min)
                    min = n;
            }
        }

        record[start][end] = min;

        return min;
    }
public:
    int minCut(string s){
        size_t len = s.size();

        if(len == 0)
            return 0;
        
        record.clear();
        vector<int> tmp(len, -1);
        record.resize(len, tmp);

        return getMinCut(s, 0, len - 1);
    }
};
*/

/* 1. Time out.
 */
/*
class Solution {
    vector<vector<int> > record;

    bool isPalindrome(string s, size_t start, size_t end){
        for(size_t i = start, j = end; i < j; i ++, j --){
            if(s[i] != s[j])
                return false;
        }

        return true;
    }

    bool oneCut(string s, size_t start, size_t end){
        for(size_t i = start + 1; i < end; i ++){
            if(isPalindrome(s, start, i) && isPalindrome(s, i + 1, end))
                return true;
        }

        return false;
    }

    int getMinCut(string s, size_t start, size_t end){
        if(record[start][end] != -1)
            return record[start][end];

        if(isPalindrome(s, start, end)){
            record[start][end] = 0;

            return 0;
        }

        if(oneCut(s, start, end))
            return 1;
    
        int min = end - start;
        for(size_t i = start; i <= end - 1; i ++){
           int n = getMinCut(s, start, i) + getMinCut(s, i + 1, end) + 1;
           if(n < min)
               min = n;
        }

        record[start][end] = min;

        return min;
    }
public:
    int minCut(string s){
        size_t len = s.size();

        if(len == 0)
            return 0;
        
        record.clear();
        vector<int> tmp(len, -1);
        record.resize(len, tmp);

        return getMinCut(s, 0, len - 1);
    }
};
*/
