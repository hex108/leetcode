#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "substring_with_concatenation_of_all_words.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        string s = "barfoothefoobarman";
        vector<string> v;
        v.push_back("foo");
        v.push_back("bar");

        print_vector(solution.findSubstring(s, v));
    }
	
    //Error test cases from leetcode.com
    {
        string s = "aaa";
        vector<string> v;
        v.push_back("a");
        v.push_back("a");

        print_vector(solution.findSubstring(s, v));
    }
	
    {
        string s="abababababababababababababababababababababababab";
        vector<string> v;
        v.push_back("ab");
        v.push_back("ba");

        print_vector(solution.findSubstring(s, v));
    }
	
    {
        string s="abababab";
        vector<string> v;
        v.push_back("a");
        v.push_back("b");
        v.push_back("a");

        print_vector(solution.findSubstring(s, v));
    }
	
	
	return 0;
}
