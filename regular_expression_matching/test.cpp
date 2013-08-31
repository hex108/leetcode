#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "regular_expression_matching.h"

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
        char *p = (char *)"ab.";
        cout << solution.isMatch(s, p) << endl;
    }
	
    {
        char *s = (char *)"abcdefh"; 
        char *p = (char *)"ab.*h";
        cout << solution.isMatch(s, p) << endl;
    }
	
    {
        char *s = (char *)"abc"; 
        char *p = (char *)".b.";
        cout << solution.isMatch(s, p) << endl;
    }
	
    {
        char *s = (char *)"c"; 
        char *p = (char *)"c.*.*";
        cout << solution.isMatch(s, p) << endl;
    }
	
    {
        char *s = (char *)"aa"; 
        char *p = (char *)"a";
        cout << solution.isMatch(s, p) << endl;
    }
	
    {
        char *s = (char *)"abc"; 
        char *p = (char *)"a.b";
        cout << solution.isMatch(s, p) << endl;
    }

    //Error test cases from leetcode.com
    {
        char *s = (char *)"aab"; 
        char *p = (char *)"c*a*b";
        cout << solution.isMatch(s, p) << endl;
    }

    {
        char *s = (char *)"bbbba"; 
        char *p = (char *)".*a*a";
        cout << solution.isMatch(s, p) << endl;
    }

	
	return 0;
}
