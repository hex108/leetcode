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
    vector<int> reverse_max;

    void fillMax(vector<int> &prices){
        int len = prices.size();
        
        int index_min, index_max, max_diff;

        index_min = index_max = 0;
        max_diff = 0;
        max[0] = 0;

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
            max[i] = max_diff;
        }
    }

    void fillReverseMax(vector<int> &prices){
        int len = prices.size();
        
        int index_min, index_max, max_diff;

        index_min = index_max = len - 1;
        max_diff = 0;
        reverse_max[len - 1] = 0;
        
        for(int i = len - 2; i >= 0; i --){
            if(prices[i] <= prices[index_min]){
                max_diff = prices[index_max] - prices[i];
                index_min = i;
            }else if(prices[i] > prices[index_max]){
                index_max = i;
            }else if(index_max <= index_min){
                int diff = prices[index_max] - prices[i];
                if(diff > max_diff){
                    index_min = i;
                    max_diff = diff;
                }
            }
            reverse_max[i] = max_diff;
        }
    }
public:
    int maxProfit(vector<int> &prices) {
        int len = prices.size();

        if(len <= 0)
            return 0;

        max.resize(len);
        fillMax(prices);

        reverse_max.resize(len);
        fillReverseMax(prices);

        int max_sum = 0;
        if(max[len - 1] > reverse_max[0]){
            max_sum = max[len - 1];
        }else{
            max_sum = reverse_max[0];
        }

        for(int i = 0; i < len -1; i ++){
            int sum = max[i] + reverse_max[i + 1];
            if(sum > max_sum)
                max_sum = sum;
        }

        return max_sum;
    }
};
