/* Notes:
 *
 */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

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
    // preorder visit
    void do_flatten(TreeNode *root, TreeNode *&tail){
        if(root == NULL)
            return;

        TreeNode *left = root->left;
        TreeNode *right = root->right;

        tail->right = root;
        tail->left = NULL;
        tail = root;
        
        do_flatten(left, tail);
        do_flatten(right, tail);
    }

public:
    void flatten(TreeNode *root) {
        TreeNode dummy_node(0); 
        TreeNode *tail = &dummy_node;

        do_flatten(root, tail);
    }
};
