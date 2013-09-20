#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "unique_paths_2.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int a[][3] = {
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0}
        };
        vector<vector<int> > v;
        arr_of_arr_to_vec(v, a[0], 3, 3);

        cout << solution.uniquePathsWithObstacles(v) << endl;
    }

    //Error test cases from leetcode.com
	
	return 0;
}
