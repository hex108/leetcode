#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "generate_parentheses.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int n = 3;
        print_vector(solution.generateParenthesis(n));
    }
	
    //Error test cases from leetcode.com
    {
        int n = 4;
        print_vector(solution.generateParenthesis(n));
    }
	
	
	return 0;
}
