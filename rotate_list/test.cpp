#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "rotate_list.h"

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
        print_list_node(solution.rotateRight(&n1, 2));
    }
	
    {
        ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4;
        n4.next = &n5;
        print_list_node(solution.rotateRight(&n1, 5));
    }
	
    {
        ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4;
        n4.next = &n5;
        print_list_node(solution.rotateRight(&n1, 0));
    }
	
    {
        ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4;
        n4.next = &n5;
        print_list_node(solution.rotateRight(&n1, 7));
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
