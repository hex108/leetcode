#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "maximum_subarray.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        int n = sizeof(a) / sizeof(a[0]);

        cout << solution.maxSubArray(a, n) << endl;
    }
	
    {
        int a[] = {-2, -11, -3, -1};
        int n = sizeof(a) / sizeof(a[0]);

        cout << solution.maxSubArray(a, n) << endl;
    }
	
    {
        int a[] = {3, 2, 4, 1};
        int n = sizeof(a) / sizeof(a[0]);

        cout << solution.maxSubArray(a, n) << endl;
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
