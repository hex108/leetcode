#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "gray_code.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int n = 2;

        print_vector(solution.grayCode(n));
    }
	
    {
        int n = 3;

        print_vector(solution.grayCode(n));
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
