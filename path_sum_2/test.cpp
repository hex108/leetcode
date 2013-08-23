#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
#include "path_sum_2.h"

using namespace std;

int main()
{
    Solution solution;
    
    //Test cases
    TreeNode t1(5);
    TreeNode t2(4);
    TreeNode t3(8);
    t1.left = &t2;
    t1.right = &t3;

    TreeNode t4(11);
    t2.left = &t4;

    TreeNode t5(13);
    TreeNode t6(4);
    t3.left = &t5;
    t3.right = &t6;

    TreeNode t7(7);
    TreeNode t8(2);
    t4.left = &t7;
    t4.right = &t8;

    TreeNode t9(5);
    TreeNode t10(1);
    t6.left = &t9;
    t6.right = &t10;

    print_vector_vector(solution.pathSum(&t1, 22));
    print_vector_vector(solution.pathSum(&t1, 80));

    //Error test cases from leetcode.com
	
	return 0;
}
