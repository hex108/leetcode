#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "first_missing_positive.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int a[] = {1, 2, 0};
        cout << solution.firstMissingPositive(a, sizeof(a)/sizeof(a[0])) << endl;
    }
	
    {
        int a[] = {3, 4, -1, 1};
        cout << solution.firstMissingPositive(a, sizeof(a)/sizeof(a[0])) << endl;
    }
	
    //Error test cases from leetcode.com
    {
        int a[] = {};
        cout << solution.firstMissingPositive(a, sizeof(a)/sizeof(a[0])) << endl;
    }
	
    {
        int a[] = {1, 1};
        cout << solution.firstMissingPositive(a, sizeof(a)/sizeof(a[0])) << endl;
    }
	
    {
        int a[] = {2, 2, 2, 2, 2};
        cout << solution.firstMissingPositive(a, sizeof(a)/sizeof(a[0])) << endl;
    }
	
	
	return 0;
}
