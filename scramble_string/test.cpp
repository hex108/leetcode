#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "scramble_string.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        string s1 = "great";
        string s2 = "rgtae";

        cout << solution.isScramble(s1, s2) << endl;
    }
	
    {
        string s1 = "great";
        string s2 = "rgtam";

        cout << solution.isScramble(s1, s2) << endl;
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
