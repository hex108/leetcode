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
#include <cmath>

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
    int minDepth(TreeNode *root) {
        if(root == NULL)
            return 0;

        if(root->left == NULL && root->right == NULL)
            return 1;

        int min;
        if(root->left && root->right){
            int left_depth = minDepth(root->left);
            int right_depth = minDepth(root->right);
            min = left_depth < right_depth? left_depth : right_depth;
        }else if(root->left){
            min = minDepth(root->left);
        }else{
            min = minDepth(root->right);
        }

        return min + 1;
    }
};
