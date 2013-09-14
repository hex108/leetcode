#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "populating_next_right_pointers_in_each_node.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        TreeLinkNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7);
        n1.left = &n2;
        n1.right = &n3;
        n2.left = &n4;
        n2.right = &n5;
        n3.left = &n6;
        n3.right = &n7;
        
        solution.connect(&n1);
        draw_tree(&n1, "1.dot"); 
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
