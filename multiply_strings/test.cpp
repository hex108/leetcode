#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "multiply_strings.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        string s1 = "22";
        string s2 = "22";

        cout << solution.multiply(s1, s2) << endl;
    }
	
    {
        string s1 = "99";
        string s2 = "8888";

        cout << solution.multiply(s1, s2) << endl;
    }
	
    //Error test cases from leetcode.com
    {
        string s1 = "98";
        string s2 = "9";

        cout << solution.multiply(s1, s2) << endl;
    }
	
    {
        string s1 = "9133";
        string s2 = "0";

        cout << solution.multiply(s1, s2) << endl;
    }
	
	
	return 0;
}
