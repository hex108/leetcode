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
    bool is_same_structure(TreeNode *p, TreeNode *q){
        int n1 = 0;
        if(p->left)
            n1 += 1;
        if(p->right)
            n1 += 2;

        int n2 = 0;
        if(q->left)
            n2 += 1;
        if(q->right)
            n2 += 2;
        
        return n1 == n2;
    }

public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p == NULL)
            return q == NULL;
        
        if(q == NULL)
            return p == NULL;
        
        if(p->val != q->val)
            return false;

        if(is_same_structure(p, q) == false)
            return false;
    
        if(isSameTree(p->left, q->left) == false)
            return false;

        if(isSameTree(p->right, q->right) == false)
            return false;

        return true;
    }
};
