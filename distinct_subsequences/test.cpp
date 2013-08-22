#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "distinct_subsequences.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    string S = "rabbbit";
    string T = "rabbit";
    cout << solution.numDistinct(S, T) << endl;
	
    S = "rabbbit";
    T = "rabiit";
    cout << solution.numDistinct(S, T) << endl;

    S = "rabbbit";
    T = "";
    cout << solution.numDistinct(S, T) << endl;

    S = "rabrab";
    T = "rab";
    cout << solution.numDistinct(S, T) << endl;

    //Error test cases from leetcode.com
	
	return 0;
}

