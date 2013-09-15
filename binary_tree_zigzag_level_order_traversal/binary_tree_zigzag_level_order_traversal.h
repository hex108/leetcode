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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > zigzag_levels;
        if(root == NULL)
            return zigzag_levels;
        
        vector<TreeNode *> cur_level_nodes;
        cur_level_nodes.push_back(root);

        bool need_revered = false;
        while(cur_level_nodes.size() != 0){
            vector<int> cur_level_values;
            vector<TreeNode *> next_level_nodes;
    
            for(size_t i = 0; i < cur_level_nodes.size(); i ++){
                TreeNode *node = cur_level_nodes[i];
                cur_level_values.push_back(node->val);

                if(node->left)
                    next_level_nodes.push_back(node->left);
                
                if(node->right)
                    next_level_nodes.push_back(node->right);
            }

            if(need_revered == true){
                reverse(cur_level_values.begin(), cur_level_values.end());
                need_revered = false;
            }else
                need_revered = true;

            zigzag_levels.push_back(cur_level_values);
            cur_level_nodes.swap(next_level_nodes);
        }

        return zigzag_levels;
    }
};
