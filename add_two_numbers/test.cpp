#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "add_two_numbers.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        ListNode n1(2), n2(4), n3(3), n4(5), n5(6), n6(4);
        n1.next = &n2;
        n2.next = &n3;

        n4.next = &n5;
        n5.next = &n6;

        print_list_node(solution.addTwoNumbers(&n1, &n4));
    }
	
    {
        ListNode n1(2), n2(4), n3(9), n4(9), n5(9), n6(9);
        n1.next = &n2;

        n3.next = &n4;
        n4.next = &n5;
        n5.next = &n6;

        print_list_node(solution.addTwoNumbers(&n1, &n3));
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
