#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "add_binary.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        string a = "11";
        string b = "1";

        cout << solution.addBinary(a, b) << endl;
    }
	
    {
        string a = "11";
        string b = "11";

        cout << solution.addBinary(a, b) << endl;
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
