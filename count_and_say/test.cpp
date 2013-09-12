#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "count_and_say.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int n = 3;
        cout << solution.countAndSay(n) << endl;
    }
	
    {
        int n = 5;
        cout << solution.countAndSay(n) << endl;
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
