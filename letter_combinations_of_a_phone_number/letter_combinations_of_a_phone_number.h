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
    void init_num_map(map<int, string> &num_to_letters){
        string str="abcdefghijklmnopqrstuvwxyz";
        for(int i = 2; i <= 6; i ++)
            num_to_letters[i] = str.substr((i - 2) * 3, 3);

        num_to_letters[7] = str.substr(15, 4);
        num_to_letters[8] = str.substr(19, 3);
        num_to_letters[9] = str.substr(22, 4);
    }

    void add_letters(vector<string> &combinations, string letters){
        size_t size = combinations.size();
        if(size == 0){
            for(size_t i = 0; i < letters.size(); i ++)
                combinations.push_back(letters.substr(i, 1));
            return;
        }

        vector<string> tmp;
        for(size_t i = 0; i < size; i ++){
            string str = combinations[i];
            for(size_t j = 0; j < letters.size(); j ++){
                tmp.push_back(str + letters.substr(j, 1));
            }
        }
        combinations.swap(tmp);
    }

public:
    vector<string> letterCombinations(string digits) {
        map<int, string> num_to_letters;
        init_num_map(num_to_letters);

        vector<string> combinations;
        for(size_t i = 0; i < digits.size(); i ++){
            int n = digits[i] - '0';
            if(n <= 1)
                continue;
            string letters = num_to_letters[n];
            add_letters(combinations, letters);
        }

        // The system asks for it!
        if(combinations.size() == 0){
            combinations.push_back("");
        }

        return combinations;
    }
};
