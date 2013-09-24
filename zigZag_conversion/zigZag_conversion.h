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
    map<int, int> record1; // dummy to real
    map<int, int> record2; // real to dummy

    void init(){
        record1.clear();
        record2.clear();
    }

    void set_real_index(int &index){
        if(record2.count(index)){
            int tmp = index;
            index = record2[tmp];
            // record2.erase(tmp);
        }
    }

    void swap_with_offset(string &s, int offset, int dummy_index){
        int real = offset;
        if(record1.count(offset)){
            real = record1[offset];
            // record1.erase(offset);
        }

        swap(s[offset], s[dummy_index]); 
        record2[real] = dummy_index;
        record1[dummy_index] = real;
    }

public:
    string convert(string s, int nRows) {
        if(s.size() == 0)
            return s;

        init();

        int end = s.size() - 1;

        int offset = 0;
        for(int i = 0; i <= nRows - 1; i ++){
            cout << "Row " << i << endl;
            int j = 0;
            while(1){
                if(i == 0){
                    int index = j * (2 * nRows - 2); 
                    if(index > end)
                        break;

                    set_real_index(index);
                    swap_with_offset(s, offset, index);
                }else if(i == nRows - 1){
                    int index = (j + 1) * (nRows - 1);
                    if(index > end)
                        break;

                    set_real_index(index);
                    swap_with_offset(s, offset, index);
                }else{
                    int index1 = j * (2 * nRows - 2) - i;
                    if(index1 > end)
                        break;
                    if(index1 >= 0){
                        set_real_index(index1);
                        swap_with_offset(s, offset, index1);
                    }

                    int index2 = j * (2 * nRows - 2 ) + i;
                    if(index2 > end)
                        break;
                    set_real_index(index2);
                    swap_with_offset(s, offset, index2);
                }

                offset ++;
                j ++;
            }
        }

        return s;
    }
};

/* Memory Limit Exceed
class Solution {
public:
    string convert(string s, int nRows) {
        string converted_str;
        if(s.size() == 0)
            return converted_str;

        int end = s.size() - 1;
        int addend = 2 * nRows - 2;

        for(int i = 0; i <= nRows - 1; i ++){
            for(int j = i; j <= end; j += addend){
                converted_str.push_back(s[j]);     
                
                int k = j + 2 * (nRows - 1 - i);
                if(k > j + nRows - 1 - i && k < j + addend && k <= end)
                    converted_str.push_back(s[k]);
            }
        }

        return converted_str;
    }
};
*/
