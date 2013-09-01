/* Notes:
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

#include "test.h"
using namespace std;

class Solution {
    // pre: num is sorted ascending.
    void record_non_negative_int(vector<int> &num, map<int, int> &record){
        for(int i = num.size() - 1; i >= 0; i --){
            if(num[i] < 0)
                break;
            int n = num[i];
            record[n] ++;
        }
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
    vector<vector<int> > threeSum(vector<int> &num) {
        map<int, int> record;
        vector<vector<int> > three_nums;

        sort(num.begin(), num.end());
        record_non_negative_int(num, record); 
        
        size_t size = num.size();
        for(size_t i = 0; i < size;){
            if(num[i] >= 0)
                break;

            for(size_t j = i + 1; j < size;){
                int n1 = num[i], n2 = num[j];
                if(n1 + n2 > 0)
                    break;

                int remain = 0 - n1 - n2;
                if(remain < n2)
                    break;

                if((n2 == remain && record.count(remain) && record[remain] >= 2) 
                    || (n2 != remain && record.count(remain))){
                    vector<int> tmp;
                    tmp.push_back(num[i]);
                    tmp.push_back(num[j]);
                    tmp.push_back(remain);

                    three_nums.push_back(tmp);
                }

                j = skip_same_number(num, j);
            }
            i = skip_same_number(num, i);
        }

        if(record[0] >= 3){
            vector<int> tmp(3, 0); 
            three_nums.push_back(tmp); // [0, 0, 0]
        }

        return three_nums;
    }
};
