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
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if(n == 0)
            return;

        for(int start = 0, end = n - 1; start < end; start ++, end--){
            for(int i = start; i < end; i ++){
                int offset = i - start;
                int tmp = matrix[start][i];
                matrix[start][i] = matrix[end - offset][start];
                matrix[end - offset][start] = matrix[end][end - offset];
                matrix[end][end - offset] = matrix[i][end];
                matrix[i][end] = tmp;
            }
        }
    }
};
