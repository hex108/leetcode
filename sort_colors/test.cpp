#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "sort_colors.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int a[] = {1, 2, 0, 1, 2, 0, 0, 1, 1, 2};
        int size = sizeof(a) / sizeof(a[0]);
        
        solution.sortColors(a, size);
        
        print_arr(a, size);
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
