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
    int maxProfit(vector<int> &prices) {
        if(prices.size() < 2) 
            return 0;

        int profit = 0;
        for(int buy = 0; buy < prices.size() - 1;){
            int sell = buy + 1;
            while(sell < prices.size() && prices[sell] >= prices[sell - 1])
                sell ++;

            if(sell > buy + 1)
                profit += prices[sell - 1] - prices[buy];

            buy = sell;
        }

        return profit;
    }
};
