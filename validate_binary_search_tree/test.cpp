#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "validate_binary_search_tree.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        // true
        TreeNode n1(4), n2(2), n3(5), n4(3), n5(6);
        n1.left = &n2;
        n1.right = &n3;
        n2.right = &n4;
        n3.right = &n5;

        cout << solution.isValidBST(&n1) << endl;
    }
	
    {
        // true
        TreeNode n1(4), n2(6), n3(5), n4(3), n5(6);
        n1.left = &n2;
        n1.right = &n3;
        n2.right = &n4;
        n3.right = &n5;

        cout << solution.isValidBST(&n1) << endl;
    }
	
    //Error test cases from leetcode.com
    {
        // false
        TreeNode n1(1), n2(1);
        n1.left = &n2;

        cout << solution.isValidBST(&n1) << endl;
    }
	
	return 0;
}
