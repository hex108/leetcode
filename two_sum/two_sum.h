/* Notes: Map/Hash is very very useful.
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> record;
        vector<int> indexs;

        for(size_t i = 0; i < numbers.size(); i ++){
            int n = numbers[i];

            if(record.count(n)){
                indexs.push_back(record[n]);
                indexs.push_back(i + 1);

                return indexs;
            }else{
                int remain = target - n;
                record[remain] = i + 1;
            }
        }

        return indexs;
    }
};
