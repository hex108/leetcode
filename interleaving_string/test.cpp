#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "interleaving_string.h"

using namespace std;

int main()
{
    Solution solution;

    //Test cases
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    cout << solution.isInterleave(s1, s2, s3) << endl;

    s3 = "aadbbbaccc";
    cout << solution.isInterleave(s1, s2, s3) << endl;
	
    s1 = "abad";
    s2 = "acae";
    s3 = "acabaade";
    cout << solution.isInterleave(s1, s2, s3) << endl;

    //Error test cases from leetcode.com
	
	return 0;
}
