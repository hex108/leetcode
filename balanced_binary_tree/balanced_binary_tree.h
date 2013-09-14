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
    // If root is balanced tree, return its height, otherwise return -1.
    int get_height(TreeNode *root){
        if(root == NULL)
            return 0;

        int left_height = get_height(root->left);
        if(left_height == -1)
            return -1;

        int right_height = get_height(root->right);
        if(right_height == -1)
            return -1;

        int root_height;
        if(right_height >= left_height && right_height - left_height <= 1)
            root_height = right_height + 1;
        else if(left_height > right_height && left_height - right_height <= 1)
            root_height = left_height + 1;
        else
            root_height = -1;

        return root_height;
    }
public:
    bool isBalanced(TreeNode *root) {
         int height = get_height(root); 

         return height != -1;
    }
};
