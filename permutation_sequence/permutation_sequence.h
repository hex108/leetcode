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
    vector<int> fn; // record the value of 'n!'
    
    void fill_fn(int n){
        fn.resize(n + 1); // fn[0] is not used for convinience.

        int val = 1;
        for(int i = 1; i <= n; i ++){
            val = val * i;
            fn[i] = val;
            // cout << "fn[" << i << "] = " << val << endl;
        }
    }

    void init_num(vector<int> &num, int n){
        for(int i = 1; i <= n; i ++)
            num.push_back(i);
    }

    string vector_to_string(vector<int> &num){
        string str;

        int size = num.size();
        for(int i = 0; i < size; i ++){
            str += ('0' + num[i]);
        }

        return str;
    }

    string do_get_permutation(vector<int> &num, vector<int> &remain_num, int k){
        if(k == 1){
            num.insert(num.end(), remain_num.begin(), remain_num.end());

            return vector_to_string(num);
        }

        int end = remain_num.size() - 1;
        int step = fn[end];
        for(int i = 0; i <= end; i ++){
            if(k > step){
                k -= step;
                continue;
            }
            int n = remain_num[i];
            num.push_back(n);
            remain_num.erase(remain_num.begin() + i);

            return do_get_permutation(num, remain_num, k);
        }

        return "";
    }
public:
    // Pre: 1 <= n <= 9
    string getPermutation(int n, int k) {
        fill_fn(n);

        /* 'remain_num' record what numbers left to fill the permutation.
         * 'num' record the permutation.
         */
        vector<int> remain_num, num;
        init_num(remain_num, n);

        return do_get_permutation(num, remain_num, k);
    }
};
