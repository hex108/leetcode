#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "remove_nth_node_from_end_of_list.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4;
        n4.next = &n5;
        int n = 2;
        print_list_node(solution.removeNthFromEnd(&n1, n));
    }
	
    {
        ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4;
        n4.next = &n5;
        int n = 1;
        print_list_node(solution.removeNthFromEnd(&n1, n));
    }
	
    {
        ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4;
        n4.next = &n5;
        int n = 5;
        print_list_node(solution.removeNthFromEnd(&n1, n));
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
