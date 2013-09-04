#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "next_permutation.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int a[] = {1, 2, 3};
        vector<int> v;
        INT_ARR_TO_VEC(v, a);

        solution.nextPermutation(v);
        print_vector(v);
    }
	
    {
        int a[] = {3, 2, 1};
        vector<int> v;
        INT_ARR_TO_VEC(v, a);

        solution.nextPermutation(v);
        print_vector(v);
    }
	
    {
        int a[] = {1, 1, 5};
        vector<int> v;
        INT_ARR_TO_VEC(v, a);

        solution.nextPermutation(v);
        print_vector(v);
    }
	
    {
        int a[] = {1, 5, 1};
        vector<int> v;
        INT_ARR_TO_VEC(v, a);

        solution.nextPermutation(v);
        print_vector(v);
    }
	
    //Error test cases from leetcode.com
    {
        int a[] = {1, 3, 2};
        vector<int> v;
        INT_ARR_TO_VEC(v, a);

        solution.nextPermutation(v);
        print_vector(v);
    }
	
    {
        int a[] = {4, 2, 0, 2, 3, 2, 0};
        vector<int> v;
        INT_ARR_TO_VEC(v, a);

        solution.nextPermutation(v);
        print_vector(v);
    }
	
	
	return 0;
}
