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
    int max;

    int maxSum(TreeNode *node){
        if(node == NULL)
            return 0;

        int left = maxSum(node->left);
        int right = maxSum(node->right);
        int val = node->val;

        int sum = left + right + val;
        if(sum > max)
            max = sum;

        sum = val;
        int big = left > right? left : right;
        if(big > 0){
            sum += big;           
        }
        if(sum > max){
            max = sum;
        }

        return sum;
    }
public:
    int maxPathSum(TreeNode *root) {
        if(root == NULL)
            return 0;
        
        max = root->val;
        maxSum(root);

        return max;
    }
};
