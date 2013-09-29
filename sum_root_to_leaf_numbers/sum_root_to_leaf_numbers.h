/* Notes:
 *
 */
#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
#include <cmath>

#include "test.h"
using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int sumTree(TreeNode *root, int sum){
        if(root == NULL)
            return 0;

        sum = sum * 10 + root->val;

        if(root->left == NULL && root->right == NULL){
            return sum;
        }

        int tree_sum = 0;
        if(root->left)
            tree_sum += sumTree(root->left, sum);

        if(root->right)
            tree_sum += sumTree(root->right, sum);

        return tree_sum;
    }

public:
    int sumNumbers(TreeNode *root) {
        return sumTree(root, 0);
    }
};
