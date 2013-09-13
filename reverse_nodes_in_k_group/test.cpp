#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "reverse_nodes_in_k_group.h"

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

        int k = 2;
        print_list_node(solution.reverseKGroup(&n1, k));
    }
	
    {
        ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4;
        n4.next = &n5;

        int k = 3;
        print_list_node(solution.reverseKGroup(&n1, k));
    }
	
    {
        ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4;
        n4.next = &n5;

        int k = 8;
        print_list_node(solution.reverseKGroup(&n1, k));
    }
	
    {
        ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4;
        n4.next = &n5;

        int k = 5;
        print_list_node(solution.reverseKGroup(&n1, k));
    }
	
    //Error test cases from leetcode.com
    {
        // misunderstand the question
        ListNode n1(1), n2(2);
        n1.next = &n2;

        int k = 3;
        print_list_node(solution.reverseKGroup(&n1, k));
    }

    {
        ListNode n1(1), n2(2), n3(3), n4(4);
        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4;

        int k = 2;
        print_list_node(solution.reverseKGroup(&n1, k));
    }
    
	return 0;
}
