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
    TreeNode *build_tree(vector<int> &preorder, int pre_start, int pre_end,
                            vector<int> &inorder, int in_start, int in_end){
        if(pre_start > pre_end)
            return NULL;

        int root_val = preorder[pre_start];
        vector<int>::iterator in_start_iter = inorder.begin() + in_start;
        vector<int>::iterator in_end_iter = inorder.begin() + in_end;
        int offset = find(in_start_iter, in_end_iter + 1, root_val) - in_start_iter; 

        TreeNode *root = new TreeNode(root_val);
        TreeNode *left = build_tree(preorder, pre_start + 1, pre_start + offset,
                                    inorder, in_start, in_start + offset - 1);
        TreeNode *right = build_tree(preorder, pre_start + offset + 1, pre_end,
                                    inorder, in_start + offset + 1, in_end);
        
        root->left = left;
        root->right = right;

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return build_tree(preorder, 0, preorder.size() - 1, 
                          inorder, 0, inorder.size() - 1);
    }
};

/* memory limit exceed.
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.size() == 0)
            return NULL;

        int root_val = preorder[0];
        int offset = find(inorder.begin(), inorder.end(), root_val) - inorder.begin();

        vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + offset + 1);
        vector<int> right_preorder(preorder.begin() + offset + 1, preorder.end());
        
        vector<int> left_inorder(inorder.begin(), inorder.begin() + offset);
        vector<int> right_inorder(inorder.begin() + offset + 1, inorder.end());

        TreeNode *root = new TreeNode(root_val);
        TreeNode *left = buildTree(left_preorder, left_inorder);
        TreeNode *right = buildTree(right_preorder, right_inorder);

        root->left = left;
        root->right = right;

        return root;
    }
};
*/
