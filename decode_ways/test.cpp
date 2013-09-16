#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "decode_ways.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        string s("12");

        cout << solution.numDecodings(s) << endl;
    }
	
    {
        string s("123");

        cout << solution.numDecodings(s) << endl;
    }
	
    //Error test cases from leetcode.com
    {
        string s("0");

        cout << solution.numDecodings(s) << endl;
    }
	
    {
        string s("10");

        cout << solution.numDecodings(s) << endl;
    }
	
	
	return 0;
}
