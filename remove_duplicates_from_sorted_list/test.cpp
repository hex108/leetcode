#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "remove_duplicates_from_sorted_list.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        ListNode n1(1), n2(1), n3(2);
        n1.next = &n2;
        n2.next = &n3;
        print_list_node(solution.deleteDuplicates(&n1));
    }
	
    {
        ListNode n1(1), n2(1), n3(2), n4(3), n5(3);
        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4;
        n4.next = &n5;
        print_list_node(solution.deleteDuplicates(&n1));
    }
	
    {
        print_list_node(solution.deleteDuplicates(NULL));
    }

    {
        ListNode n1(1), n2(2), n3(3);
        n1.next = &n2;
        n2.next = &n3;
        print_list_node(solution.deleteDuplicates(&n1));
    }

    //Error test cases from leetcode.com
	
	return 0;
}
