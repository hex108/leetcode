#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "palindrome_number.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int n = -12321;
        cout << solution.isPalindrome(n) << endl;
    }
	
    {
        int n = 12321;
        cout << solution.isPalindrome(n) << endl;
    }
	
    {
        int n = 12341;
        cout << solution.isPalindrome(n) << endl;
    }
	
    //Error test cases from leetcode.com
    {
        int n = 1001;
        cout << solution.isPalindrome(n) << endl;
    }
	
	
	return 0;
}
