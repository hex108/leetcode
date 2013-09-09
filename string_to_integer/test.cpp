#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "string_to_integer.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        char *str = "1234";
        cout << solution.atoi(str) << endl;
    }
	
    {
        char *str = "-1234";
        cout << solution.atoi(str) << endl;
    }
	
    {
        char *str = "   -1234ab12";
        cout << solution.atoi(str) << endl;
    }
	
    {
        char *str = "-2147483648";
        cout << solution.atoi(str) << endl;
    }
	
    {
        char *str = "2147483647";
        cout << solution.atoi(str) << endl;
    }
	
    //Error test cases from leetcode.com
    {
        char *str = "2147483648";
        cout << solution.atoi(str) << endl;
    }
	
    {
        char *str = "    10522545459";
        cout << solution.atoi(str) << endl;
    }
	
	
	return 0;
}
