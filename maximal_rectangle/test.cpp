#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "maximal_rectangle.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        char a[][5] = {
            {'1', '0', '1', '1', '1'},
            {'1', '0', '1', '1', '0'},
            {'0', '0', '1', '1', '1'},
            {'1', '0', '1', '0', '1'},
        };

        vector<vector<char> > v;
        arr_of_arr_to_vec(v, a[0], 4, 5);

        cout << solution.maximalRectangle(v) << endl;
    }
	
    //Error test cases from leetcode.com
	
	return '0';
}
