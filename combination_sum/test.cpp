#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "combination_sum.h"

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

        print_vector_vector(solution.combinationSum(v, target));
    }
	
    {
        int a[] = {2, 3, 6, 7};
        vector<int> v;
        INT_ARR_TO_VEC(v, a);

        int target = 0;

        print_vector_vector(solution.combinationSum(v, target));
    }
	
    {
        int a[] = {2, 3, 6, 7};
        vector<int> v;
        INT_ARR_TO_VEC(v, a);

        int target = 20;

        print_vector_vector(solution.combinationSum(v, target));
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
