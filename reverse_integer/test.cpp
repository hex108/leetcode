#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <climits>

#include "test.h"
#include "reverse_integer.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int n = 123;
        cout << solution.reverse(n) << endl;
    }
	
    {
        int n = 1200;
        cout << solution.reverse(n) << endl;
    }
	
    {
        int n = -123;
        cout << solution.reverse(n) << endl;
    }
	
    {
        int n = INT_MIN;
        cout << solution.reverse(n) << endl;
    }
	
    {
        int n = 1234567899;
        cout << solution.reverse(n) << endl;
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
