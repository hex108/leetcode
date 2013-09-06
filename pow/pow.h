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
    map<int, double> record;

    double get_pow(double x, int n){
        if(n == 1)
            return x;
        else if(n == 0)
            return 1;
        
        if(record.count(n))
            return record[n];

        double half = get_pow(x, n / 2);
        double ret = half * half;
        if(n % 2)
            ret = ret * x; 

        record[n] = ret;

        return ret;
    }
public:
    double pow(double x, int n) {
        record.clear();

        if(n >= 0){
            return get_pow(x, n);
        }else{
            // 'n' might be the smallest negative '-2147483648'
            double ret = get_pow(x, -(n + 1)) * x;
            return 1/ret;
        }
    }
};
