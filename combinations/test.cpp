#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "combinations.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int n = 4;
        int k = 2;
        print_vector_vector(solution.combine(n, k)); 
    }
	
    {
        int n = 4;
        int k = 0;
        print_vector_vector(solution.combine(n, k)); 
    }
	
    {
        int n = 0;
        int k = 2;
        print_vector_vector(solution.combine(n, k)); 
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
