#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "longest_common_prefix.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        string a = "abcdefg";
        string b = "abcdfge";
        string c = "abcdgfe";
        string d = "abcdegf";
        vector<string> strs;
        strs.push_back(a);
        strs.push_back(b);
        strs.push_back(c);
        strs.push_back(d);

        cout << solution.longestCommonPrefix(strs) << endl;
    }
	
    {
        string a = "abcdefg";
        string b = "abcdfge";
        string c = "accdfe";
        string d = "abcdegf";
        vector<string> strs;
        strs.push_back(a);
        strs.push_back(b);
        strs.push_back(c);
        strs.push_back(d);

        cout << solution.longestCommonPrefix(strs) << endl;
    }
	
    {
        string a = "abcdefg";
        string b = "abcdfge";
        string c = "bbcdgfe";
        string d = "abcde";
        vector<string> strs;
        strs.push_back(a);
        strs.push_back(b);
        strs.push_back(c);
        strs.push_back(d);

        cout << solution.longestCommonPrefix(strs) << endl;
    }
	
    {
        string a = "abcdefg";
        string b = "abcdfge";
        string c = "abcdgfe";
        string d = "";
        vector<string> strs;
        strs.push_back(a);
        strs.push_back(b);
        strs.push_back(c);
        strs.push_back(d);

        cout << solution.longestCommonPrefix(strs) << endl;
    }
	
    {
        vector<string> strs;

        cout << solution.longestCommonPrefix(strs) << endl;
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
