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
    TreeNode *build_tree(vector<int> &inorder, int in_start, int in_end,
                   vector<int> &postorder, int post_start, int post_end){
        // cout << "[" << in_start << ", " << in_end << "], ";
        // cout << "[" << post_start << ", " << post_end << "], " << endl;

        if(in_start > in_end)
            return NULL;

        if(in_start == in_end){
            TreeNode *node = new TreeNode(inorder[in_start]);
            return node;
        }
        
        int root_val = postorder[post_end];
        vector<int>::iterator in_start_iter = inorder.begin() + in_start;
        vector<int>::iterator in_end_iter = inorder.begin() + in_end;
        int offset = find(in_start_iter, in_end_iter + 1, root_val) - in_start_iter;
        
        TreeNode *root = new TreeNode(root_val);
        TreeNode *left = build_tree(inorder, in_start, in_start + offset - 1,
                                    postorder, post_start, post_start + offset - 1);
        TreeNode *right = build_tree(inorder, in_start + offset + 1, in_end,
                                    postorder, post_start + offset, post_end - 1);

        root->left = left;
        root->right = right;

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return build_tree(inorder, 0, inorder.size() - 1, 
                          postorder, 0, postorder.size() - 1);
    }
};
