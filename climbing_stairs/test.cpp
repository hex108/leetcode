#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "climbing_stairs.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    cout << solution.climbStairs(0) << endl;
	
    cout << solution.climbStairs(1) << endl;
	
    cout << solution.climbStairs(5) << endl;
	
    //Error test cases from leetcode.com
	
	return 0;
}
