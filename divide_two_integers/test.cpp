#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "divide_two_integers.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int a = 12;
        int b = 3;
        cout << solution.divide(a, b) << endl;
    }
	
    {
        int a = 12;
        int b = 5;
        cout << solution.divide(a, b) << endl;
    }
	
    //Error test cases from leetcode.com
    {
        // time out
        int a = 2147483647;
        int b = 1;
        cout << solution.divide(a, b) << endl;
    }
	
    {
        // time out
        int a = -2147483648;
        int b = -2147483648;
        cout << solution.divide(a, b) << endl;
    }
	
    {
        // time out
        int a = -2147483648;
        int b = 1;
        cout << solution.divide(a, b) << endl;
    }
	
	
	return 0;
}
