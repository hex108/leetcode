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
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > different_level_values; 
        if(root == NULL)
            return different_level_values;

        vector<TreeNode *> cur_level_nodes;
        cur_level_nodes.push_back(root);

        while(cur_level_nodes.size() != 0){
            vector<TreeNode *> next_level_nodes;
            vector<int> cur_level_values;

            for(size_t i = 0; i < cur_level_nodes.size(); i ++){
                TreeNode *node = cur_level_nodes[i];
                cur_level_values.push_back(node->val);

                if(node->left)
                    next_level_nodes.push_back(node->left); 

                if(node->right)
                    next_level_nodes.push_back(node->right);
            }

            different_level_values.push_back(cur_level_values); 
            cur_level_nodes.swap(next_level_nodes);
        }

        reverse(different_level_values.begin(), different_level_values.end());

        return different_level_values;
    }
};
