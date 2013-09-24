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
    string get_str(int n, int base){
        string s;

        if(base == 1000)
            s.append(n, 'M');
        else if(base == 100)
            s = get_specific_str(n, 'M', 'D', 'C');
        else if(base == 10)
            s = get_specific_str(n, 'C', 'L', 'X');
        else if(base == 1)
            s = get_specific_str(n, 'X', 'V', 'I');

        return s;
    }

    string get_specific_str(int n, char base_num_10, char base_num_5, 
                            char base_num_1){
        string s; 

        if(n == 9){
            s.push_back(base_num_1);
            s.push_back(base_num_10);
        }else if(n == 4){
            s.push_back(base_num_1);
            s.push_back(base_num_5);
        }else{
            if(n >= 5){
                s.push_back(base_num_5);
                n -= 5;
            }

            if(n > 0)
                s.append(n, base_num_1);
        }

        return s;
    }

public:
    string intToRoman(int num) {
        string s;
        
        int base = 1000;
        while(base){
            int n = num / base; 
            s.append(get_str(n, base));

            num = num % base;
            base = base / 10;
        }

        return s;
    }
};
