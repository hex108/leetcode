#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "text_justification.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        char *a[7] = {
            "This", "is", "an", "example", "of", "text", "justification."
        };
        vector<string> v;
        for(int i = 0; i < 7; i ++)
            v.push_back(a[i]);

        int L = 16;

        print_vector(solution.fullJustify(v, L));
    }
	
    //Error test cases from leetcode.com
    {
        vector<string> v;
        v.push_back("");

        int L = 0;

        print_vector(solution.fullJustify(v, L));
    }
	
	
	return 0;
}
