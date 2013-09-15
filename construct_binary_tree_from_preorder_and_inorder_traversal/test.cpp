#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "construct_binary_tree_from_preorder_and_inorder_traversal.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int a[] = {1, 2, 4, 3, 5, 6};
        vector<int> pre_oder;
        INT_ARR_TO_VEC(pre_oder, a);

        int b[] = {2, 4, 1, 5, 3, 6};
        vector<int> in_oder;
        INT_ARR_TO_VEC(in_oder, b);

        draw_tree(solution.buildTree(pre_oder, in_oder), "1.dot");
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
