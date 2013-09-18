#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "search_a_2D_matrix.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int a[][4] = {
            {1, 3, 5, 7},
            {10, 11, 16, 20},
            {23, 30, 34, 50}
        };

        vector<vector<int> > v;
        arr_of_arr_to_vec(v, a[0], 3, 4);

        int target = 3;
        
        cout << solution.searchMatrix(v, target) << endl;
    }
	
    {
        int a[][4] = {
            {1, 3, 5, 7},
            {10, 11, 16, 20},
            {23, 30, 34, 50}
        };

        vector<vector<int> > v;
        arr_of_arr_to_vec(v, a[0], 3, 4);

        int target = 21;
        
        cout << solution.searchMatrix(v, target) << endl;
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
