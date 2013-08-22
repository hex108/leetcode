#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "palindrome_partitioning.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    string str = "aab";
    print_vector_vector(solution.partition(str));
	
    str = "a";
    print_vector_vector(solution.partition(str));
	
    str = "";
    print_vector_vector(solution.partition(str));
	
    //Error test cases
    str = "bb";
    print_vector_vector(solution.partition(str));
	
	return 0;
}
