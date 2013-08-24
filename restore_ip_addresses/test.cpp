#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "restore_ip_addresses.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    string s = "25525511135";
    print_vector(solution.restoreIpAddresses(s));
	
    s = "255255111353333";
    print_vector(solution.restoreIpAddresses(s));
	
    s = "2552";
    print_vector(solution.restoreIpAddresses(s));
	
    s = "255";
    print_vector(solution.restoreIpAddresses(s));
	
    s = "2552002102";
    print_vector(solution.restoreIpAddresses(s));
	
    //Error test cases from leetcode.com
	
	return 0;
}
