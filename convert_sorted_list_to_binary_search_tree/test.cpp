#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "convert_sorted_list_to_binary_search_tree.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        ListNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6);
        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4;
        n4.next = &n5;
        n5.next = &n6;

        draw_tree(solution.sortedListToBST(&n1), "1.dot");
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
