#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "longest_valid_parentheses.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    { // 4
        string s = ")()())";
        cout << solution.longestValidParentheses(s) << endl;
    }
	
    { // 6
        string s = ")(())())";
        cout << solution.longestValidParentheses(s) << endl;
    }
	
    { // 4
        string s = "))(()()";
        cout << solution.longestValidParentheses(s) << endl;
    }
	
    { // 0
        string s = "";
        cout << solution.longestValidParentheses(s) << endl;
    }
	
    //Error test cases from leetcode.com
    { // 2
        string s = "()(()";
        cout << solution.longestValidParentheses(s) << endl;
    }
	
    { // 6
        string s = "()(())";
        cout << solution.longestValidParentheses(s) << endl;
    }
	
	
	return 0;
}
