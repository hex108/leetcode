#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "longest_palindromic_substring.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        string s = "abcddcefgh";
        cout << solution.longestPalindrome(s) << endl;
    }

    {
        string s = "abcdefg";
        cout << solution.longestPalindrome(s) << endl;
    }
	
    {
        string s = "abcddcefabccbade";
        cout << solution.longestPalindrome(s) << endl;
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
