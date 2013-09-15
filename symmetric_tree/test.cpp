#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "symmetric_tree.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    {
        // true
        TreeNode n1(1), n2(2), n3(2), n4(3), n5(4), n6(4), n7(3);
        n1.left = &n2;
        n1.right = &n3;
        n2.left = &n4;
        n2.right = &n5;
        n3.left = &n6;
        n3.right = &n7;

        cout << solution.isSymmetric(&n1) << endl;
    }
	
    {
        // false 
        TreeNode n1(1), n2(2), n3(2), n4(3), n6(3);
        n1.left = &n2;
        n1.right = &n3;
        n2.right = &n4;
        n3.right = &n6;

        cout << solution.isSymmetric(&n1) << endl;
    }
	
    //Error test cases from leetcode.com
	
	return 0;
}
