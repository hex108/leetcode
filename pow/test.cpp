#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "pow.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        double x = 2.5;
        int n = 2;
        cout << solution.pow(x, n) << endl;
    }
	
    {
        double x = 2.5;
        int n = 0;
        cout << solution.pow(x, n) << endl;
    }
	
    {
        double x = 2.5;
        int n = 1;
        cout << solution.pow(x, n) << endl;
    }
	
    {
        double x = 2.5;
        int n = 5;
        cout << solution.pow(x, n) << endl;
    }
	
    //Error test cases from leetcode.com
    {
        double x = 1.0;
        int n = -1;
        cout << solution.pow(x, n) << endl;
    }
	
	
    {
        double x = 1.0;
        int n = -2147483648;
        cout << solution.pow(x, n) << endl;
    }
	
	return 0;
}
