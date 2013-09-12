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
public:
    string countAndSay(int n) {
        string s = "1"; 

        for(int i = 1; i < n; i ++){
            string tmp; 

            for(size_t j = 0; j < s.size(); ){
                char c = s[j];
                int count = 1;
                j ++;
                while(j < s.size() && s[j] == c){
                    count ++;
                    j ++;
                }
                tmp.push_back('0' + count);
                tmp.push_back(c);
            }

            s = tmp;
        }

        return s;
    }
};
