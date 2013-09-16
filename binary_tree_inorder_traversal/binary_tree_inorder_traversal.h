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
// version two: no need for flag
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> values;   
        // record nodes to be visisted
        stack<TreeNode *> nodes;

        TreeNode *cur_node = root;
        while(cur_node != NULL || nodes.size() != 0){
            while(cur_node != NULL){
                nodes.push(cur_node);
                cur_node = cur_node->left;
            }
            
            cur_node = nodes.top();
            nodes.pop();
            values.push_back(cur_node->val);

            cur_node = cur_node->right;
        }

        return values;
    }
};

// version one
/*
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> values;   
        if(root == NULL)
            return values;

        // record nodes to be visisted
        stack<TreeNode *> nodes;
        // record whether corresponding node in 'nodes' has been visited
        stack<bool> visited; 

        nodes.push(root);
        visited.push(false);

        while(nodes.size() != 0){
            TreeNode *node = nodes.top();
            nodes.pop();
            bool is_visited = visited.top();
            visited.pop();

            if(is_visited == true){
                values.push_back(node->val);
            }else{
                if(node->right){
                    nodes.push(node->right);
                    visited.push(false);
                }

                nodes.push(node);
                visited.push(true);

                if(node->left){
                    nodes.push(node->left);
                    visited.push(false);
                }
            }
        }

        return values;
    }
};
*/
