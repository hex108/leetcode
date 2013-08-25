#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "remove_duplicates_from_sorted_list_2.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        ListNode n1(1), n2(2), n3(3), n4(3), n5(4), n6(4), n7(5);
        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4;
        n4.next = &n5;
        n5.next = &n6;
        n6.next = &n7;
        print_list_node(solution.deleteDuplicates(&n1));
    }
	
    {
        ListNode n1(1), n2(1), n3(1), n4(2), n5(3);
        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4;
        n4.next = &n5;
        print_list_node(solution.deleteDuplicates(&n1));
    }
	
    {
        ListNode n1(1), n2(1), n3(1), n4(2), n5(2);
        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4;
        n4.next = &n5;
        print_list_node(solution.deleteDuplicates(&n1));
    }
	
    {
        ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4;
        n4.next = &n5;
        print_list_node(solution.deleteDuplicates(&n1));
    }
	
    {
        print_list_node(solution.deleteDuplicates(NULL));
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
