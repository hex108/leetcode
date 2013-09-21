#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "n-Queens.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int n = 4;

        print_vector_vector(solution.solveNQueens(n));
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
