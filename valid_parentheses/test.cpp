#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "valid_parentheses.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        string s = "[](){}";
        cout << solution.isValid(s) << endl;
    }
	
    {
        string s = "[(){}]";
        cout << solution.isValid(s) << endl;
    }
	
    {
        string s = "[](){{}";
        cout << solution.isValid(s) << endl;
    }
	
    {
        string s = "[(]){}";
        cout << solution.isValid(s) << endl;
    }
	
    {
        string s = "[()]]{}";
        cout << solution.isValid(s) << endl;
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
