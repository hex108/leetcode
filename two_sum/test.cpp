#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "two_sum.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    vector<int> numbers;

    int a[] = {2, 7, 11, 15};
    INT_ARR_TO_VEC(numbers, a);
    int target = 9;
    print_vector(solution.twoSum(numbers, target));
	
    int b[] = {9, 2, 5, 3, 4, 7};
    INT_ARR_TO_VEC(numbers, b);
    target = 9;
    print_vector(solution.twoSum(numbers, target));
	
    //Error test cases from leetcode.com
	
	return 0;
}
