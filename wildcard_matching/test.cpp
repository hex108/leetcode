#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "wildcard_matching.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        char *s = (char *)"ab"; 
        char *p = (char *)"ab";
        cout << solution.isMatch(s, p) << endl;
    }
	
    {
        char *s = (char *)"abc"; 
        char *p = (char *)"ab?";
        cout << solution.isMatch(s, p) << endl;
    }
	
    {
        char *s = (char *)"abcdefh"; 
        char *p = (char *)"ab*f?";
        cout << solution.isMatch(s, p) << endl;
    }
	
    {
        char *s = (char *)"a"; 
        char *p = (char *)"?";
        cout << solution.isMatch(s, p) << endl;
    }
	
    {
        char *s = (char *)"a"; 
        char *p = (char *)"a**";
        cout << solution.isMatch(s, p) << endl;
    }
	
    {
        char *s = (char *)"abc"; 
        char *p = (char *)"a*b";
        cout << solution.isMatch(s, p) << endl;
    }
	
    //Error test cases from leetcode.com
    {
        char *s = (char *)"c"; 
        char *p = (char *)"*?*";
        cout << solution.isMatch(s, p) << endl;
    }
	
	
	return 0;
}
