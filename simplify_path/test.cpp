#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "simplify_path.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        string s = "/home/";

        cout << solution.simplifyPath(s) << endl;
    }
	
    {
        string s = "/a/./b/../../c/";

        cout << solution.simplifyPath(s) << endl;
    }
	
    //Error test cases from leetcode.com
    {
        string s = "/a/.b/c/";

        cout << solution.simplifyPath(s) << endl;
    }
	
	
	return 0;
}
