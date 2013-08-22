#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "palindrome_partitioning_2.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    string s = "aab";
    cout << solution.minCut(s) << endl;
	
    s = "";
    cout << solution.minCut(s) << endl;
	
    s = "a";
    cout << solution.minCut(s) << endl;
	
    s = "abba";
    cout << solution.minCut(s) << endl;
	
    s = "abbacdc";
    cout << solution.minCut(s) << endl;
	
    //Error test cases from leetcode.com
	
	return 0;
}
