#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "search_in_rotated_sorted_array_2.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int a[] = {4, 5, 5, 7, 0, 1, 2};
        int target = 5;
        cout << solution.search(a, sizeof(a) / sizeof(a[0]), target) << endl;
    }
	
    {
        int a[] = {4, 5, 6, 7, 8, 8, 10};
        int target = 8;
        cout << solution.search(a, sizeof(a) / sizeof(a[0]), target) << endl;
    }

    {
        int a[] = {4, 5, 6, 7, 0, 1, 2};
        int target = 3;
        cout << solution.search(a, sizeof(a) / sizeof(a[0]), target) << endl;
    }

    //Error test cases from leetcode.com
    {
        int a[] = {3, 1};
        int target = 3;
        cout << solution.search(a, sizeof(a) / sizeof(a[0]), target) << endl;
    }
	
    {
        int a[] = {3, 1};
        int target = 3;
        cout << solution.search(a, sizeof(a) / sizeof(a[0]), target) << endl;
    }

	return 0;
}
