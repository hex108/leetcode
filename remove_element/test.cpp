#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "remove_element.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int a[] = {1, 2, 2, 3, 2, 5, 3};
        int element = 2;
        int n = solution.removeElement(a, sizeof(a) / sizeof(a[0]), element);
        print_arr(a, n);
    }
	
    {
        int a[] = {1, 2, 2, 3, 2};
        int element = 2;
        int n = solution.removeElement(a, sizeof(a) / sizeof(a[0]), element);
        print_arr(a, n);
    }
	
    {
        int a[] = {1, 2, 2, 3, 2, 5, 3};
        int element = 6;
        int n = solution.removeElement(a, sizeof(a) / sizeof(a[0]), element);
        print_arr(a, n);
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
