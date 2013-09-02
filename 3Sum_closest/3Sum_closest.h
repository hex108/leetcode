/* Notes:
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <stdlib.h>

#include "test.h"
using namespace std;

class Solution {
    // Fin the largest value that saftisfys <= target
    int find_le_target(vector<int> &num, int start, int end, int target){
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(num[mid] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }

        return start - 1;
    }

    int get_min_abs(int i, int j, int target){
        if(abs(i - target) < abs(j - target))
            return i;
        else
            return j;
    }

    size_t skip_same_number(vector<int> &num, size_t start){
        size_t end = start + 1;
        int number = num[start];
        while(end < num.size() && num[end] == number){
            end ++;
        }

        return end;
    }
public:
    int threeSumClosest(vector<int> &num, int target) {
        int sum = num[0] + num[1] + num[2];

        sort(num.begin(), num.end());
        
        size_t size = num.size();
        for(size_t i = 0; i < size;){
            for(size_t j = i + 1; j < size;){
                int n1 = num[i], n2 = num[j];
                int remain = target - n1 - n2;
                
                int k = find_le_target(num, j + 1, num.size() - 1, remain);
                if(k + 1 < (int)size)
                    sum = get_min_abs(n1 + n2 + num[k + 1], sum, target);

                if(k <= (int)j)
                    break;
                
                sum = get_min_abs(n1 + n2 + num[k], sum, target);

                j = skip_same_number(num, j);
            }
            i = skip_same_number(num, i);
        }

        return sum;
    }
};
