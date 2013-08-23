#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "edit_distance.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    string w1 = "abc";
    string w2 = "abc";
    cout << solution.minDistance(w1, w2) << endl;
	
    w1 = "";
    w2 = "abc";
    cout << solution.minDistance(w1, w2) << endl;
	
    w1 = "";
    w2 = "";
    cout << solution.minDistance(w1, w2) << endl;
	
    w1 = "abe";
    w2 = "cde";
    cout << solution.minDistance(w1, w2) << endl;
	
    w1 = "abc";
    w2 = "ac";
    cout << solution.minDistance(w1, w2) << endl;
	
    w1 = "ac";
    w2 = "adc";
    cout << solution.minDistance(w1, w2) << endl;
	
    //Error test cases from leetcode.com
    w1 = "a";
    w2 = "b";
    cout << solution.minDistance(w1, w2) << endl;
	
	
	return 0;
}
