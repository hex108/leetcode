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
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // That 'left' is NULL indicates 'right'. 
        if(root == NULL || root->left == NULL)
            return;

        TreeLinkNode *left = root->left;
        TreeLinkNode *right = root->right;
        while(left != NULL && right != NULL){
             left->next = right; 

             left = left->right;
             right = right->left;
        }

        connect(root->left);
        connect(root->right);
    }
};
