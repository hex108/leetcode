#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "same_tree.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        // true
        TreeNode n1(1), n2(2), n3(3), n4(4);
        n1.left = &n2;
        n1.right = &n3;
        n2.right = &n4;


        TreeNode n5(1), n6(2), n7(3), n8(4);
        n5.left = &n6;
        n5.right = &n7;
        n6.right = &n8;

        cout << solution.isSameTree(&n1, &n5) << endl;
    }

    {
        // false
        TreeNode n1(1), n2(2), n3(3), n4(4);
        n1.left = &n2;
        n1.right = &n3;
        n2.right = &n4;


        TreeNode n5(1), n6(2), n7(3), n8(4);
        n5.left = &n6;
        n5.right = &n7;
        n6.left = &n8;

        cout << solution.isSameTree(&n1, &n5) << endl;
    }

    //Error test cases from leetcode.com
	
	return 0;
}
