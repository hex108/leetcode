/* Notes: Recursion, and record effectively.
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
    vector<vector<int> > record;

    void set_val_by_bool(int &val, bool b){
        if(b)
            val = 1;
        else
            val = 0;
    }

    bool getIsInterleave(string s1, size_t index1, string s2, size_t index2, string s3) {
        if(record[index1][index2] != -1)
            return record[index1][index2] == 1;

        if(s1.size() == 0){
            bool tmp = s2 == s3;
            set_val_by_bool(record[index1][index2], tmp);
            return tmp;
        }
            
        if(s2.size() == 0){
            bool tmp = s1 == s3;
            set_val_by_bool(record[index1][index2], tmp);
            return tmp;
        }
        
        bool ret = false;

        if(s1[0] == s3[0] && s2[0] == s3[0]){
            bool ret_tmp = getIsInterleave(s1.substr(1), index1 + 1, s2, index2, s3.substr(1));
            if(ret_tmp)
                ret = ret_tmp;

            ret_tmp = getIsInterleave(s1, index1, s2.substr(1), index2 + 1, s3.substr(1));
            if(ret_tmp)
                ret = ret_tmp;
        }else if(s1[0] == s3[0]){
            ret = getIsInterleave(s1.substr(1), index1 + 1, s2, index2, s3.substr(1));
        }else if(s2[0] == s3[0]){
            ret = getIsInterleave(s1, index1, s2.substr(1), index2 + 1, s3.substr(1));
        }

        set_val_by_bool(record[index1][index2], ret);

        return ret;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        size_t len1 = s1.size();
        size_t len2 = s2.size();
        size_t len3 = s3.size();
        
        if(len1 == 0)
            return s2 == s3;

        if(len2 == 0)
            return s1 == s3;

        if(len3 == 0 || len1 + len2 != len3)
            return false;

        record.clear();
        vector<int> tmp(len2 + 1, -1); 
        record.resize(len1 + 1, tmp);

        return getIsInterleave(s1, 0, s2, 0, s3);
    }
};

/* Exceed memory limit!!! 
 */
/*
class Solution {
    vector<vector<vector<int> > > record;

    void set_val_by_bool(int &val, bool b){
        if(b)
            val = 1;
        else
            val = 0;
    }

    bool getIsInterleave(string s1, size_t index1, string s2, size_t index2, string s3, size_t index3) {
        if(record[index1][index2][index3] != -1)
            return record[index1][index2][index3] == 1;

        if(s1.size() == 0){
            bool tmp = s2 == s3;
            set_val_by_bool(record[index1][index2][index3], tmp);
            return tmp;
        }
            
        if(s2.size() == 0){
            bool tmp = s1 == s3;
            set_val_by_bool(record[index1][index2][index3], tmp);
            return tmp;
        }
        
        bool ret = false;

        if(s1[0] == s3[0] && s2[0] == s3[0]){
            bool ret_tmp = getIsInterleave(s1.substr(1), index1 + 1, s2, index2, s3.substr(1), index3 + 1);
            if(ret_tmp)
                ret = ret_tmp;

            ret_tmp = getIsInterleave(s1, index1, s2.substr(1), index2 + 1, s3.substr(1), index3 + 1);
            if(ret_tmp)
                ret = ret_tmp;
        }else if(s1[0] == s3[0]){
            ret = getIsInterleave(s1.substr(1), index1 + 1, s2, index2, s3.substr(1), index3 + 1);
        }else if(s2[0] == s3[0]){
            ret = getIsInterleave(s1, index1, s2.substr(1), index2 + 1, s3.substr(1), index3 + 1);
        }

        set_val_by_bool(record[index1][index2][index3], ret);

        return ret;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        size_t len1 = s1.size();
        size_t len2 = s2.size();
        size_t len3 = s3.size();
        
        if(len1 == 0)
            return s2 == s3;

        if(len2 == 0)
            return s1 == s3;

        if(len3 == 0 || len1 + len2 != len3)
            return false;

        record.clear();
        vector<int> tmp1(len3, -1); 
        vector<vector<int> > tmp2(len2 + 1, tmp1);
        record.resize(len1 + 1, tmp2);

        return getIsInterleave(s1, 0, s2, 0, s3, 0);
    }
};
*/
