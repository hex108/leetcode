#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "construct_binary_tree_from_inorder_and_postorder_traversal.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        int a[] = {2, 4, 1, 5, 3, 6};
        vector<int> in_oder;
        INT_ARR_TO_VEC(in_oder, a);

        int b[] = {4, 2, 5, 6, 3, 1};
        vector<int> post_oder;
        INT_ARR_TO_VEC(post_oder, b);

        draw_tree(solution.buildTree(in_oder, post_oder), "1.dot");
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
