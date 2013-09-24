#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "anagrams.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        char *a[] = {
            "test", "hello", "loleh", "", "lehlo", "hello9"
        };

        vector<string> v;

        for(int i = 0; i < sizeof(a) / sizeof(a[0]); i ++){
            v.push_back(a[i]);
        }

        print_vector(solution.anagrams(v));
    }
	
    //Error test cases from leetcode.com
    {
        char *a[] = {
            "tea","and","ate","eat","dan"
        };

        vector<string> v;

        for(int i = 0; i < sizeof(a) / sizeof(a[0]); i ++){
            v.push_back(a[i]);
        }

        print_vector(solution.anagrams(v));
    }
	
    {
        char *a[] = {
            "and", "dan"
        };

        vector<string> v;

        for(int i = 0; i < sizeof(a) / sizeof(a[0]); i ++){
            v.push_back(a[i]);
        }

        print_vector(solution.anagrams(v));
    }
	
	
	return 0;
}
