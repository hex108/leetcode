#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "search_insert_position.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int a[] = {1, 3, 5, 6};
        int target = 5;
        
        cout << solution.searchInsert(a, sizeof(a) / sizeof(a[0]), target) << endl;
    }
	
    {
        int a[] = {1, 3, 5, 6};
        int target = 2;
        
        cout << solution.searchInsert(a, sizeof(a) / sizeof(a[0]), target) << endl;
    }
	
    {
        int a[] = {1, 3, 5, 6};
        int target = 7;
        
        cout << solution.searchInsert(a, sizeof(a) / sizeof(a[0]), target) << endl;
    }
	
    {
        int a[] = {1, 3, 5, 6};
        int target = 0;
        
        cout << solution.searchInsert(a, sizeof(a) / sizeof(a[0]), target) << endl;
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
