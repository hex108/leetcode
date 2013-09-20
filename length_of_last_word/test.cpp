#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "length_of_last_word.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        char *s = "Hello world";

        cout << solution.lengthOfLastWord(s) << endl;
    }
	
    {
        char *s = "  ";

        cout << solution.lengthOfLastWord(s) << endl;
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
