#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "4Sum.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int a[] = {1, 0, -1, 0, -2, 2};
        vector<int> v;
        INT_ARR_TO_VEC(v, a);

        int target = 0;
        print_vector_vector(solution.fourSum(v, target));
    }
	
    {
        int a[] = {1, 0, -1, 0, -2, 2};
        vector<int> v;
        INT_ARR_TO_VEC(v, a);

        int target = 20;
        print_vector_vector(solution.fourSum(v, target));
    }
	
    {
        vector<int> v;

        int target = 0;
        print_vector_vector(solution.fourSum(v, target));
    }
	
    //Error test cases from leetcode.com
    {
        int a[] = {-1, 0, 1, 2, -1, -4};
        vector<int> v;
        INT_ARR_TO_VEC(v, a);

        int target = -1;
        print_vector_vector(solution.fourSum(v, target));
    }
	
    {
        int a[] = {0, 4, -5, 2, -2, 4, 2, -1, 4};
        vector<int> v;
        INT_ARR_TO_VEC(v, a);

        int target = 12;
        print_vector_vector(solution.fourSum(v, target));
    }
	
    {
        int a[] = {-1, 0, -5, -2, -2, -4, 0, 1, -2};
        vector<int> v;
        INT_ARR_TO_VEC(v, a);

        int target = -9;
        print_vector_vector(solution.fourSum(v, target));
    }
	
    {
        int a[] = {-1, 2, 2, -5, 0, -1, 4};
        vector<int> v;
        INT_ARR_TO_VEC(v, a);

        int target = 3;
        print_vector_vector(solution.fourSum(v, target));
    }
	
	
	return 0;
}
