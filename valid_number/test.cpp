#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "valid_number.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        char a[] = "0";

        cout << solution.isNumber(a) << endl;
    }
	
    {
        char a[] = " 0.1";

        cout << solution.isNumber(a) << endl;
    }
	
    {
        char a[] = "abc";

        cout << solution.isNumber(a) << endl;
    }
	
    {
        char a[] = "1 a";

        cout << solution.isNumber(a) << endl;
    }
	
    {
        char a[] = "2e10";

        cout << solution.isNumber(a) << endl;
    }
	
    //Error test cases from leetcode.com
    {
        char a[] = "";

        cout << solution.isNumber(a) << endl;
    }
	
    {
        char a[] = ".34";

        cout << solution.isNumber(a) << endl;
    }
	
    {
        char a[] = "1e";

        cout << solution.isNumber(a) << endl;
    }
	
    {
        char a[] = "2e+0";

        cout << solution.isNumber(a) << endl;
    }
	
	
	return 0;
}
