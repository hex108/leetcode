/* Notes:
 *
 */
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <climits>

#include "test.h"
using namespace std;

class Solution {
    vector<int> record;

    void init(int n){
        record.clear();
        record.resize(n + 1, -1);

        record[0] = 1;
        record[1] = 1;
    }

    int get_num(int n){
        if(record[n] != -1)
            return record[n];

        /* pick up the i-th number as the root, 0~i-1 as left tree, i + 1 ~ n - 1
         * as right tree.
         */
        int num = 0;
        for(int i = 0; i <= n - 1; i ++){
            num += get_num(i) * get_num(n - 1 - i);
        }

        record[n] = num;

        return num;
    }
public:
    int numTrees(int n) {
        if(n <= 0)
            return 1;

        init(n);     

        return get_num(n);
    }
};
