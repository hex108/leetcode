/* Notes: 10.001.1.2 is not IP addr.
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
    vector<string> add_addr(vector<string> addr, string s){
        if(addr.size() == 0){
            addr.push_back(s);
            return addr; 
        }

        s = "." + s;
        vector<string>::iterator iter;
        for(iter = addr.begin(); iter != addr.end(); iter ++){
            iter->append(s);
        }

        return addr;
    }

    bool valid_addr(string s){
        if(s.size() == 0 || s.size() > 3)
            return false;
        
        if(s[0] == '0')
            return s.size() == 1;

        unsigned int n = s[0] - '0';
        for(size_t i = 1; i < s.size(); i ++){
            n = n * 10 + (s[i] - '0');    
        }

        return n <= 255;
    }

    vector<string> getIpAddresses(string s, int remain, vector<string> pre_addr){
        vector<string> addr;

        if(remain == 1){
           if(valid_addr(s)){
               addr = add_addr(pre_addr, s);
           }
           return addr;
        }
    
        for(size_t i = 0; i < s.size(); i ++){
            string sub_str = s.substr(0, i + 1);
            if(!valid_addr(sub_str)){
                break;
            }

            vector<string> cur_addr = add_addr(pre_addr, sub_str);
            vector<string> tmp = getIpAddresses(s.substr(i + 1), remain - 1, cur_addr);

            addr.insert(addr.end(), tmp.begin(), tmp.end());
        }

        return addr;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> addr;

        addr = getIpAddresses(s, 4, addr);

        return addr;
    }
};
