#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "3Sum.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int a[] = {-1, 0, 1, 2, -1, -4};
        vector<int> v;
        INT_ARR_TO_VEC(v, a);

        print_vector_vector(solution.threeSum(v));
    }
	
    {
        int a[] = {-1, 0, 1, 0, 2, -1, 0, 2, -4};
        vector<int> v;
        INT_ARR_TO_VEC(v, a);

        print_vector_vector(solution.threeSum(v));
    }

    {
        int a[] = {-1, 0, 18, 9, -30, -4};
        vector<int> v;
        INT_ARR_TO_VEC(v, a);

        print_vector_vector(solution.threeSum(v));
    }

    //Error test cases from leetcode.com
    {
        vector<int> v;

        print_vector_vector(solution.threeSum(v));
    }

	
	return 0;
}
