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
    int longestConsecutive(vector<int> &num) {
        if(num.size() == 0)
            return 0;

        map<int, int> record;
        int max_len = 1;

        for(size_t i = 0; i < num.size(); i ++){
            int n = num[i];

            if(record.count(n) != 0)
                continue;
            else
                record[n] = n;
            
            int head = n, tail = n;

            if(n != INT_MIN && record.count(n - 1))
                head = record[n - 1];

            if(n != INT_MAX && record.count(n + 1))
                tail = record[n + 1];

            record[head] = tail;
            record[tail] = head;
            max_len = max(max_len, tail - head + 1);
        }

        return max_len;
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
