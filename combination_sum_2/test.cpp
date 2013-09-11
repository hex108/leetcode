#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "combination_sum_2.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int a[] = {2, 3, 6, 7};
        vector<int> v;
        INT_ARR_TO_VEC(v, a);

        int target = 7;

        print_vector_vector(solution.combinationSum2(v, target));
    }
	
    {
        int a[] = {2, 3, 6, 7};
        vector<int> v;
        INT_ARR_TO_VEC(v, a);

        int target = 0;

        print_vector_vector(solution.combinationSum2(v, target));
    }
	
    {
        int a[] = {10, 1, 2, 7, 6, 1, 5};
        vector<int> v;
        INT_ARR_TO_VEC(v, a);

        int target = 8;

        print_vector_vector(solution.combinationSum2(v, target));
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
