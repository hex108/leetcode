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
    vector<int> getRow(int rowIndex) {
        vector<int> tmp1, tmp2;

        for(int i = 1; i <= rowIndex + 1; i ++){
            tmp2.resize(i);
            tmp2[0] = tmp2[i - 1] = 1;

            for(int j = 1; j <= (i - 1) / 2; j ++)
                tmp2[j] = tmp2[i - 1 - j] = tmp1[j - 1] + tmp1[j];
            
            tmp2.swap(tmp1);
        }

        return tmp1;
    }
};
