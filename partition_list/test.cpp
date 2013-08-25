#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "partition_list.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        ListNode n1(1), n2(4), n3(3), n4(2), n5(5), n6(2);
        int x = 3;
        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4;
        n4.next = &n5;
        n5.next = &n6;
        print_list_node(solution.partition(&n1, x));
    }

    {
        ListNode n1(1), n2(4), n3(3), n4(2), n5(5), n6(2);
        int x = 7;
        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4;
        n4.next = &n5;
        n5.next = &n6;
        print_list_node(solution.partition(&n1, x));
    }

    {
        ListNode n1(1), n2(4), n3(3), n4(2), n5(5), n6(2);
        int x = 0;
        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4;
        n4.next = &n5;
        n5.next = &n6;
        print_list_node(solution.partition(&n1, x));
    }

    //Error test cases from leetcode.com
	
	return 0;
}
