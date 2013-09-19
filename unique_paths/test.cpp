#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "unique_paths.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int m = 3, n = 7;

        cout << solution.uniquePaths(m, n) << endl;
    }
	
    {
        int m = 99, n = 100;

        cout << solution.uniquePaths(m, n) << endl;
    }
	
    {
        int m = 100, n = 100;

        cout << solution.uniquePaths(m, n) << endl;
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
