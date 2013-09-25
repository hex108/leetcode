#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "zigZag_conversion.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        string s = "PAYPALISHIRING";
        int n = 3;

        cout << solution.convert(s, n) << endl;
    }
	
    {
        string s = "abcdefghigklmasdfasdfasdfasdfasdf";
        int n = 5;

        cout << solution.convert(s, n) << endl;
    }

    //Error test cases from leetcode.com
    {
        string s = "PAYPALISHIRING";
        int n = 2;

        cout << solution.convert(s, n) << endl;
    }
	
	return 0;
}
