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
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > triangle;
        
        if(numRows <= 0)
            return triangle;

        vector<int> tmp1,tmp2;
        for(int i = 1; i <= numRows; i ++){
            tmp2.resize(i);
            tmp2[0] = tmp2[i - 1] = 1;

            for(int j = 1; j <= (i - 1) / 2; j++)
                tmp2[j] = tmp2[i - 1 - j] = tmp1[j - 1] + tmp1[j];
            
            triangle.push_back(tmp2);
            tmp2.swap(tmp1);
        }

        return triangle;
    }
};
