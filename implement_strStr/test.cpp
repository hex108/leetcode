#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "implement_strStr.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        char *haystack = "ababababd", *needle = "ababd";

        char *ret = solution.strStr(haystack, needle);

        string s = ret? ret : "NULL";
        cout << s << endl;
    }
	
    {
        char *haystack = "ababababd", *needle = "ababababd";

        char *ret = solution.strStr(haystack, needle);

        string s = ret? ret : "NULL";
        cout << s << endl;
    }
	
    {
        char *haystack = "ababababd", *needle = "ababdcef";

        char *ret = solution.strStr(haystack, needle);

        string s = ret? ret : "NULL";
        cout << s << endl;
    }
	
    //Error test cases from leetcode.com
    {
        char *haystack = "", *needle = "";

        char *ret = solution.strStr(haystack, needle);

        string s = ret? ret : "NULL";
        cout << s << endl;
    }
	
    {
        // Time out
        char *haystack = "mississippi", *needle = "a";

        char *ret = solution.strStr(haystack, needle);

        string s = ret? ret : "NULL";
        cout << s << endl;
    }
	
    {
        char *haystack = "mississippi", *needle = "issip";

        char *ret = solution.strStr(haystack, needle);

        string s = ret? ret : "NULL";
        cout << s << endl;
    }
	
    {
        char *haystack = "aaabb", *needle = "baba";

        char *ret = solution.strStr(haystack, needle);

        string s = ret? ret : "NULL";
        cout << s << endl;
    }
	
    {
        // Time out
        char *haystack = "bbaa", *needle = "aab";

        char *ret = solution.strStr(haystack, needle);

        string s = ret? ret : "NULL";
        cout << s << endl;
    }
	
	return 0;
}
