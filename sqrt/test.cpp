#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "sqrt.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int x = 9;

        cout << solution.sqrt(x) << endl;
    }
	
    {
        int x = 15;

        cout << solution.sqrt(x) << endl;
    }
	
    //Error test cases from leetcode.com
    {
        int x = 3;

        cout << solution.sqrt(x) << endl;
    }
	
	
	return 0;
}
