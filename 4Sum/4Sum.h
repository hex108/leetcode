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
    void record_num(vector<int> &num, map<int, int> &record){
        for(int i = num.size() - 1; i >= 0; i --){
            int n = num[i];
            record[n] ++;
        }
    }

    void dec_record(map<int, int> &record, int num){
        if(record.count(num))
            record[num] --;
    }

    int skip_same_number(vector<int> &num, int start){
        int end = start + 1;
        int number = num[start];
        while(end < num.size() && num[end] == number){
            end ++;
        }

        return end;
    }
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        map<int, int> record;
        vector<vector<int> > four_nums;

        sort(num.begin(), num.end());
        record_num(num, record); 
        
        int size = num.size();
        for(int i = 0; i < size - 3;){
            int n1 = num[i];
            if(n1 + num[i + 1] + num[i + 2] + num[i + 3] > target)
                break;
            if(n1 + num[size - 3] + num[size - 2] + num[size - 1] < target){
                i = skip_same_number(num, i);
                continue;
            }
            
            for(int j = i + 1; j < size - 2;){
                int n2 = num[j];
                if(n1 + n2 + num[j + 1] + num[j + 2] > target)
                    break;

                for(int k = j + 1; k < size - 1;){
                    int n3 = num[k];
                    int remain = target - n1 - n2 - n3;
                    if(remain < n3)
                        break;

                    map<int, int> tmp_record = record;
                    dec_record(tmp_record, n1);
                    dec_record(tmp_record, n2);
                    dec_record(tmp_record, n3);

                    if(tmp_record.count(remain) && tmp_record[remain] >= 1){
                        vector<int> tmp;
                        tmp.push_back(n1);
                        tmp.push_back(n2);
                        tmp.push_back(n3);
                        tmp.push_back(remain);

                        four_nums.push_back(tmp);
                    }
                    k = skip_same_number(num, k);
                }
                j = skip_same_number(num, j);
            }
            i = skip_same_number(num, i);
        }

        return four_nums;
    }
};
