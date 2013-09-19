#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "minimum_path_sum.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int a[][4] = {
            {1, 2, 3, 4},
            {5, 7, 2, 1},
            {3, 1, 0, 1}
        };
        vector<vector<int> > v;
        arr_of_arr_to_vec(v, a[0], 3, 4);
        
        cout << solution.minPathSum(v) << endl;
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
