#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "merge_two_sorted_lists.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        ListNode n1(1), n2(5), n3(8), n4(2), n5(4);
        n1.next = &n2;
        n2.next = &n3;

        n4.next = &n5;
        print_list_node(solution.mergeTwoLists(&n1, &n4));
    }
    
    {
        ListNode n1(2), n2(5), n3(8), n4(2), n5(4);
        n1.next = &n2;
        n2.next = &n3;

        n4.next = &n5;
        print_list_node(solution.mergeTwoLists(&n1, &n4));
    }
	
    {
        ListNode n1(2), n2(5), n3(8);
        n1.next = &n2;
        n2.next = &n3;

        print_list_node(solution.mergeTwoLists(&n1, NULL));
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
