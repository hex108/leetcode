/* Notes:
 *
 */
#include <iostream>
#include <vector>
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
    TreeNode *first_err_node;
    TreeNode *second_err_node;

    // in-order traversal.
    void find_err_node(TreeNode *root, TreeNode *&pre){
        if(root == NULL)
            return;

        find_err_node(root->left, pre);

        /* If root->val < pre->val, then root must be in the wrong place. If it
         * is the only node satisfy this situation, then we just need swap 
         * root's and pre's value, so we record root to 'second_err_node'. 
         * e.g. { 1, 2, 4, 3, 6, 7}, we just need swap '4' and '3'.
         * when we encounters second node like this, we set it to 'set_err_node' 
         * again, it is the really error node.
         * e.g. { 1, 2, 6, 4, 3, 7}, we just need swap '6' and '3'. 
         */
        if(root->val < pre->val){
            set_err_node(pre);
            set_err_node(root);
        }

        pre = root;

        find_err_node(root->right, pre);
    }

    void set_err_node(TreeNode *node){
        if(first_err_node == NULL)
            first_err_node = node;
        else
            second_err_node = node;
    }

public:
    void recoverTree(TreeNode *root) {
        first_err_node = NULL;
        second_err_node = NULL;

        TreeNode *pre = new TreeNode(INT_MIN);
        find_err_node(root, pre);
        
        swap(first_err_node->val, second_err_node->val);
    }
};
