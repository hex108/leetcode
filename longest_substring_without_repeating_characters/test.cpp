#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "longest_substring_without_repeating_characters.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        string s = "abcabcbb";
        cout << solution.lengthOfLongestSubstring(s) << endl;
    }
	
    {
        string s = "bbbbb";
        cout << solution.lengthOfLongestSubstring(s) << endl;
    }
	
    //Error test cases from leetcode.com
    {
        string s = "abcd";
        cout << solution.lengthOfLongestSubstring(s) << endl;
    }
	
	
	return 0;
}
