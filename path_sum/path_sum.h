/* Notes:
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "test.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(root == NULL)
            return false;

        if(root->left == NULL && root->right == NULL){
            if(sum == root->val)
                return true;
            else
                return false;
        }

        int remain = sum - root->val;

        if(root->left){
            bool left = hasPathSum(root->left, remain);
            if(left)
                return true;
        }

        if(root->right){
            bool right = hasPathSum(root->right, remain);
            if(right)
                return true;
        }

        return false;
    }
};
