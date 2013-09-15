/* N
 *
 */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
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
// solve it iteratively
class Solution {
    bool is_symmetric_structure(TreeNode *node1, TreeNode *node2){
       int n1 = 0;
       if(node1->left != NULL)
           n1 += 1;
       if(node1->right != NULL)
           n1 += 2;

       int n2 = 0;
       if(node2->left != NULL)
           n2 += 2;
       if(node2->right != NULL)
           n2 += 1;

       return n1 == n2;
    }

public:
    bool isSymmetric(TreeNode *root) {
        if(root == NULL)
            return true;

        deque<TreeNode *> nodes;
        nodes.push_front(root->left);
        nodes.push_back(root->right);

        while(nodes.size() != 0){
            TreeNode *left = nodes.front();
            nodes.pop_front();
            TreeNode *right = nodes.back();
            nodes.pop_back();

            if(left == NULL && right == NULL)
                continue;
            else if(right == NULL || left == NULL)
                return false;

            if(left->val != right->val)
                return false;

            if(is_symmetric_structure(left, right) == false)
                return false;

            nodes.push_front(left->right);
            nodes.push_front(left->left);
            nodes.push_back(right->left);
            nodes.push_back(right->right);
        }

        return true;
    }
};

/*
// solve it recursivley 
class Solution {
    bool is_symmetric_structure(TreeNode *node1, TreeNode *node2){
       int n1 = 0;
       if(node1->left != NULL)
           n1 += 1;
       if(node1->right != NULL)
           n1 += 2;

       int n2 = 0;
       if(node2->left != NULL)
           n2 += 2;
       if(node2->right != NULL)
           n2 += 1;

       return n1 == n2;
    }

    bool is_symmetric(TreeNode *left, TreeNode *right){
        if(left == NULL)
            return right == NULL;

        if(right == NULL)
            return left == NULL;

        if(left->val != right->val)
            return false;
        
         // It is just an optimization that we could avoid the following call 
         // 'is_symmetric' if they are different structures.
        if(is_symmetric_structure(left, right) == false)
            return false;

        if(is_symmetric(left->left, right->right) == false)
            return false;

        if(is_symmetric(left->right, right->left) == false)
            return false;

        return true;
    }

public:
    bool isSymmetric(TreeNode *root) {
        if(root == NULL)
            return true;

        return is_symmetric(root->left, root->right);
    }
};
*/
