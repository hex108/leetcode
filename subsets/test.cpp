#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "subsets.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int a[] = {1, 2, 3};
        vector<int> v;
        INT_ARR_TO_VEC(v, a);

        print_vector_vector(solution.subsets(v));
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
