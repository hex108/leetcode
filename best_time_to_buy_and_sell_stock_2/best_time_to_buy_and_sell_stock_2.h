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
    vector<int> max;

    int getMax(vector<int> &prices, int start, int end){
        if(start >= end){
            return 0;
        }

        int trace = start;

        max[start] = 0;
        for(int i = start + 1; i <= end; i ++){
            if(prices[i] > prices[i - 1]){
                max[i] = max[i - 1] + (prices[i] - prices[i - 1]);
                trace = i;
            }else if(prices[i] >= prices[trace]){
                max[i] = max[i - 1] + (prices[i] - prices[trace]);
                trace = i;
            }else{
                max[i] = max[i - 1];
            }
        }

        return max[end];
    }

public:

    int maxProfit(vector<int> &prices) {
        int len = prices.size();

        max.resize(len);

        return getMax(prices, 0, len -1);
    }
};
