#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "binary_tree_inorder_traversal.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        TreeNode n1(1), n2(2), n3(3);
        n1.right = &n2;
        n2.left = &n3;

        print_vector(solution.inorderTraversal(&n1));
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
