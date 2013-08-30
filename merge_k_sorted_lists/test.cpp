#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "merge_k_sorted_lists.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        ListNode n1(1), n2(5), n3(8), n4(2), n5(4), n6(7), n7(9);
        n1.next = &n2;
        n2.next = &n3;

        n4.next = &n5;

        n6.next = &n7;

        vector<ListNode *> v;
        v.push_back(&n1);
        v.push_back(&n4);
        v.push_back(&n6);

        print_list_node(solution.mergeKLists(v));
    }
	
    {
        ListNode n1(1), n2(5), n3(8), n4(2), n5(4), n6(7), n7(9);
        n1.next = &n2;
        n2.next = &n3;

        n4.next = &n5;
        n5.next = &n6;
        n6.next = &n7;

        vector<ListNode *> v;
        v.push_back(&n1);
        v.push_back(&n4);
        v.push_back(NULL);

        print_list_node(solution.mergeKLists(v));
    }
	
    //Error test cases from leetcode.com
    {
        // when size_t i = 0, i --, then i = MAX_INT. Need change 'size_t' to 'int'.
        ListNode n1(1);

        vector<ListNode *> v;
        v.push_back(&n1);

        print_list_node(solution.mergeKLists(v));
    }

    {
        // Fail to build min map because forgeting to adjust the heap when swap.
        ListNode n1(-6), n2(-3), n3(-10), n4(-8), n5(-6), n6(-8), n7(-4), n8(-8), n9(-6), n10(-5);
        n1.next = &n2;

        n3.next = &n4;
        n4.next = &n5;

        n6.next = &n7;

        n8.next = &n9;
        n9.next = &n10;

        vector<ListNode *> v;
        v.push_back(&n1);
        v.push_back(&n3);
        v.push_back(&n6);
        v.push_back(&n8);

        print_list_node(solution.mergeKLists(v));
    }
	
	
	return 0;
}
