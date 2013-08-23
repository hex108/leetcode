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
    int a[] = {2, 7, 11, 15};
    vector<int> numbers(a, a + sizeof(a) / sizeof(a[0]));
    int target = 9;
    print_vector(solution.twoSum(numbers, target));
	
    int b[] = {9, 2, 5, 3, 4, 7};
    vector<int> numbers2(b, b + sizeof(b) / sizeof(b[0]));
    target = 9;
    print_vector(solution.twoSum(numbers2, target));
	
    //Error test cases from leetcode.com
	
	return 0;
}
