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
    string convert(string s, int nRows) {
        string converted_str;
        if(s.size() == 0)
            return converted_str;

        int end = s.size() - 1;
        int addend = 2 * nRows - 2;

        for(int i = 0; i <= nRows - 1; i ++){
            for(int j = i; j <= end; j += addend){
                converted_str.push_back(s[j]);     
                
                int k = j + 2 * (nRows - 1 - i);
                if(k > j + nRows - 1 - i && k < j + addend && k <= end)
                    converted_str.push_back(s[k]);
            }
        }

        return converted_str;
    }
};
