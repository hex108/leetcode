#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "minimum_window_substring.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        string s = "ADOBECODEBANC";
        string t = "ABC";

        cout << solution.minWindow(s, t) << endl;
    }
	
    {
        string s = "ADOBECODEBANC";
        string t = "ABCF";

        cout << solution.minWindow(s, t) << endl;
    }
	
    {
        string s = "ADOBECOAEBANC";
        string t = "ABC";

        cout << solution.minWindow(s, t) << endl;
    }
	
    //Error test cases from leetcode.com
    {
        string s = "a";
        string t = "a";

        cout << solution.minWindow(s, t) << endl;
    }
	
    {
        // misunderstand the question. I thought the letters in "aa" are just 'a'.
        string s = "a";
        string t = "aa";

        cout << solution.minWindow(s, t) << endl;
    }
	
    {
        string s = "acbbaca";
        string t = "aba";

        cout << solution.minWindow(s, t) << endl;
    }
	
	return 0;
}
