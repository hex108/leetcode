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
        int len = prices.size();
        
        int index_min, index_max, max_diff;

        index_min = index_max = 0;
        max_diff = 0;

        for(int i = 1; i <= len - 1; i ++){
            if(prices[i] >= prices[index_max]){
                max_diff = prices[i] - prices[index_min];
                index_max = i;
            }else if(prices[i] < prices[index_min]){
                index_min = i;
            }else if(index_min >= index_max){
                int diff = prices[i] - prices[index_min];
                if(diff > max_diff){
                    index_max = i;
                    max_diff = diff;
                }
            }
        }

        return max_diff;
    }
};
