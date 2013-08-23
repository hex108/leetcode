/* Notes: Use bits. But I think it might not be effective if the range betwwen them is 
 * too large. So I use map. Finally I solve the problem.
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <limits.h>

#include "test.h"
using namespace std;

class Solution {
public:
    unsigned int getMax(unsigned int n1, unsigned int n2){
        return n1 > n2? n1 : n2;
    }
    
    int longestConsecutive(vector<int> &num) {
        map<int, int> record;
        unsigned int max = 0;

        for(size_t i = 0; i < num.size(); i ++){
            int n = num[i];

            if(record.count(n) == 0){
                record[n] = n;
                if(max < 1)
                    max = 1;
            }else{
                continue;
            }

            if(n != INT_MIN && record.count(n - 1)){
                int pre_n = record[n - 1];
                record[pre_n] = n; 
                record[n] = pre_n;

                max = getMax((unsigned int)(n - pre_n + 1), max);
            }

            if(n != INT_MAX && record.count(n + 1)){
                int next_n = record[n + 1];
                int pre_n = record[n]; // record[n] might not be n now.
                record[next_n] = pre_n;
                record[pre_n] = next_n;

                max = getMax((unsigned int)(next_n - pre_n + 1), max);
            }
        }

        return max;
    }
};

/*
class Solution {
    unsigned int *value_exists; // simulate bit-set
    int min;

    void set_bit(unsigned int n){
        unsigned int v = (unsigned int)1 << (n % 32); // int size;
        value_exists[n / 32] |= v; 
    }

    bool is_set(unsigned int n){
        unsigned int v = (unsigned int)1 << (n % 32);
        return (unsigned int)(value_exists[n / 32] & v) != 0; 
    }

    public:
        int longestConsecutive(vector<int> &num) {
            if(num.size() == 0)
                return 0;

            int min = num[0];
            int max = num[0];
            for(vector<int>::iterator iter = num.begin(); iter != num.end(); iter ++){
                if(*iter < min)
                    min = *iter;
                else if(*iter > max)
                    max = *iter;
            }

            unsigned int size = max - min + 1;
            cout << "size : " << size << endl;
            value_exists = (unsigned int *)calloc(size / 32 + 1, sizeof(int));
            if(value_exists == NULL){
                cout << "malloc error" << endl;
                return 0;
            }
            

            for(vector<int>::iterator iter = num.begin(); iter != num.end(); iter ++){
                cout << "set " << *iter << endl;
                set_bit((unsigned int)(*iter - min));
            }

            int max_len = 0;
            for(unsigned int i = 0; i < size; i ++){
                if(i % 32 == 0 && value_exists[i / 32] == 0){
                    i += 31;
                    continue;
                }

                int len = 0;
                while(i < size && is_set(i++))
                    len ++;

                if(len > max_len)
                    max_len = len;
            }

            free(value_exists);

            return max_len;
        }
};
*/
