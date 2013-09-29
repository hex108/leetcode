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
    int minimumTotal(vector<vector<int> > &triangle) {
        int row = triangle.size();
    
        if(row <= 0)
            return 0;

        vector<int> min(triangle[row - 1]);

        for(int i = row - 2; i >= 0; i --){
            for(int j = 0; j <= i; j ++){
                if(min[j] < min[j + 1])
                    min[j] = min[j] + triangle[i][j];
                else
                    min[j] = min[j + 1] + triangle[i][j];
            }
        }

        return min[0];
    }
};
