/* Notes:
 *
 */
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <climits>

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
    TreeNode *dummy_node;
    
    // in-order traversal
    bool is_valid_bst(TreeNode *root, TreeNode *&pre){
        if(root == NULL)
            return true;
        
        if(is_valid_bst(root->left, pre) == false)
            return false;

        if(root->val <= pre->val && pre != dummy_node)
            return false;

        pre = root;

        if(is_valid_bst(root->right, pre) == false)
            return false;

        return true;
    }

public:
    bool isValidBST(TreeNode *root) {
        TreeNode *pre = new TreeNode(INT_MIN);
        dummy_node = pre;

        return is_valid_bst(root, pre);
    }
};
