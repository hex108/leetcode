#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "letter_combinations_of_a_phone_number.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        string digits = "23";
        print_vector(solution.letterCombinations(digits));
    }
	
    {
        string digits = "12340";
        print_vector(solution.letterCombinations(digits));
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
