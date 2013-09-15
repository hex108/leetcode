#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "recover_binary_search_tree.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        TreeNode n1(4), n2(3), n3(5), n5(2), n6(6);
        n1.left = &n2;
        n1.right = &n3;
        n2.right = &n5;
        n3.right = &n6;

        solution.recoverTree(&n1);
        draw_tree(&n1, "1.dot");
    }
	
    {
        TreeNode n1(4), n2(3), n3(2), n5(5), n6(6);
        n1.left = &n2;
        n1.right = &n3;
        n2.left = &n5;
        n3.left = &n6;

        solution.recoverTree(&n1);
        draw_tree(&n1, "2.dot");
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
