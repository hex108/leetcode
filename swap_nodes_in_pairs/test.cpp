#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "swap_nodes_in_pairs.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        ListNode n1(1), n2(2), n3(3), n4(4);
        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4;

        print_list_node(solution.swapPairs(&n1));  
    }
	
    {
        ListNode n1(1), n2(2), n3(3);
        n1.next = &n2;
        n2.next = &n3;

        print_list_node(solution.swapPairs(&n1));  
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
