#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "jump_game.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        // true
        int A[] = {2, 3, 1, 1, 4};
        int n = sizeof(A) / sizeof(A[0]);

        cout << solution.canJump(A, n) << endl;
    }
	
    {
        // false 
        int A[] = {3, 2, 1, 0, 4};
        int n = sizeof(A) / sizeof(A[0]);

        cout << solution.canJump(A, n) << endl;
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
