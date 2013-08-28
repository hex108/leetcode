#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "search_for_a_range.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int a[] = {5, 7, 7, 8, 8, 10};
        int target = 8;

        print_vector(solution.searchRange(a, sizeof(a) / sizeof(a[0]), target));
    }
	
    {
        int a[] = {5, 7, 7, 8, 8, 10};
        int target = 9;

        print_vector(solution.searchRange(a, sizeof(a) / sizeof(a[0]), target));
    }
	
    {
        int a[] = {5};
        int target = 9;

        print_vector(solution.searchRange(a, sizeof(a) / sizeof(a[0]), target));
    }
	
    {
        int a[] = {5};
        int target = 3;

        print_vector(solution.searchRange(a, sizeof(a) / sizeof(a[0]), target));
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
