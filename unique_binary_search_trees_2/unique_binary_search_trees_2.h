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
    vector<TreeNode *> generate_trees(int start, int end){
        vector<TreeNode *> trees;

        if(start >= end){
            if(start == end){
                TreeNode *node = new TreeNode(start);    
                trees.push_back(node);
            }else
                trees.push_back(NULL);

            return trees;
        }

        for(int i = start; i <= end; i ++){
            vector<TreeNode *> left_trees = generate_trees(start, i - 1);
            vector<TreeNode *> right_trees = generate_trees(i + 1, end);
            
            vector<TreeNode *> tmp_trees;
            tmp_trees = combine_trees(i, left_trees, right_trees);
            trees.insert(trees.end(), tmp_trees.begin(), tmp_trees.end());
        }

        return trees;
    }

    vector<TreeNode *> combine_trees(int root_val, 
              vector<TreeNode *> &left_trees, vector<TreeNode *> &right_trees){
        vector<TreeNode *> trees;

        for(size_t i = 0; i < left_trees.size(); i++){
            for(size_t j = 0; j < right_trees.size(); j ++){
                TreeNode *root = new TreeNode(root_val);
                root->left = duplicate_tree(left_trees[i]);
                root->right = duplicate_tree(right_trees[j]);

                trees.push_back(root);
            }
        }

        free_trees(left_trees);
        free_trees(right_trees);

        return trees;
    }

    TreeNode *duplicate_tree(TreeNode *root){
        if(root == NULL)
            return NULL;

        TreeNode *new_root = new TreeNode(root->val);   
        new_root->left = duplicate_tree(root->left); 
        new_root->right = duplicate_tree(root->right); 

        return new_root;
    }

    void free_trees(vector<TreeNode *> &trees){
        for(size_t i = 0; i < trees.size(); i ++)
            free_tree(trees[i]);
    }

    void free_tree(TreeNode *root){
        if(root == NULL)
            return;

        TreeNode *left = root->left;
        TreeNode *right = root->right;

        delete root;
        free_tree(left);
        free_tree(right);
    }

public:
    vector<TreeNode *> generateTrees(int n) {
        return generate_trees(1, n);
    }
};
