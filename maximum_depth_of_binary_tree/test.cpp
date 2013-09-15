#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "maximum_depth_of_binary_tree.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        TreeNode n1(1), n2(2), n3(3), n4(4);
        n1.left = &n2;
        n1.right = &n3;
        n2.left = &n4;

        cout << solution.maxDepth(&n1) << endl;
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
