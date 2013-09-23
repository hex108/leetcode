#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "n-Queens_2.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int n = 4;

        cout << solution.totalNQueens(n) << endl;
    }

    {
        int n = 12;

        cout << solution.totalNQueens(n) << endl;
    }

    //Error test cases from leetcode.com
	
	return 0;
}
