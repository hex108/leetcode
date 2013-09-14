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
    TreeNode *convert_to_bst(vector<int> &num, int start, int end){
        if(start > end)
            return NULL;

        if(start == end){
            TreeNode *node = new TreeNode(num[start]);  
            return node;
        }

        int mid = start + (end - start) / 2;
        TreeNode *root = new TreeNode(num[mid]);
        TreeNode *left = convert_to_bst(num, start, mid - 1);
        TreeNode *right = convert_to_bst(num, mid + 1, end);

        root->left = left;
        root->right = right;

        return root;
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return convert_to_bst(num, 0, num.size() - 1);    
    }
};
