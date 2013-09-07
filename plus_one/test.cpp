#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "plus_one.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int a[] = { 9, 9, 9, 9 };
        vector<int> v;
        INT_ARR_TO_VEC(v, a);

        print_vector(solution.plusOne(v));
    }
	
    {
        int a[] = { 9, 9, 9, 3 };
        vector<int> v;
        INT_ARR_TO_VEC(v, a);

        print_vector(solution.plusOne(v));
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
