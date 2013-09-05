/* Notes:
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>

#include "test.h"
using namespace std;

class Solution {
    vector<int> index;

    /* Regard it as an automatic machine, then you might understand it more 
     * clearly.
     */
    void build_index(char *needle){
        int len = strlen(needle);
        if(len < 1)
            return;
        
        index.resize(len);
        index[0] = -1;
        
        char *str = needle;
        for(int i = 1; i < len; i ++){
            char c = needle[i];
            int n = index[i - 1];

            while(n != -1 && c != needle[n + 1])
                n = index[n];
            
            if(c == needle[n + 1])
                index[i] = n + 1;
            else
                index[i] = -1;
        }

        print_vector(index);
    }
public:
    // use algorithm KMP.
    char *strStr(char *haystack, char *needle) {
        build_index(needle);

        char *str = needle;
        while(*haystack && *str){
            if( *haystack != *str){
                if(str == needle){
                    haystack ++;
                    continue;
                }

                int n = index[str - needle - 1];
                str = needle + n + 1;
            }else{
                str ++;
                haystack ++;
            }
        }

        if(*str == 0)
            return haystack - (str - needle);
        else
            return NULL;
    }
};
