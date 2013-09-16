#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "subsets_2.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int a[] = {3, 2, 1};
        vector<int> v;
        INT_ARR_TO_VEC(v, a);

        print_vector_vector(solution.subsetsWithDup(v));
    }
	
    {
        int a[] = {2, 2, 1};
        vector<int> v;
        INT_ARR_TO_VEC(v, a);

        print_vector_vector(solution.subsetsWithDup(v));
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
