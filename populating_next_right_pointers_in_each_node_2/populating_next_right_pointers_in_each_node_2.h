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
    /* Do breadth frist visit. Because we could not use extra memory, we use
     * the pointer 'next' in TreeLinkNode to simulate a vector. It works as 
     * following:
     *     vector<TreeLinkNode *> tree_nodes;
     *     tree_nodes.push_back(root);
     *
     *     while(tree_nodes.size() != 0){
     *         vector<TreeLinkNode *> tmp;
     *
     *         for(size i = 0; i < tree_nodes.size(); i ++){
     *             TreeLinkNode *node = tree_nodes[i];
     *             if(node->left)
     *                 tmp.push_back(node->left);
     *             if(node->right)
     *                 tmp.push_back(node->right);
     *         }
     *
     *         tree_nodes.swap(tmp);
     *     }
     */
    void connect(TreeLinkNode *root) {
        TreeLinkNode dummy_node(0);
        dummy_node.next = root;

        while(dummy_node.next){
            TreeLinkNode *start = dummy_node.next;
            dummy_node.next = NULL;

            TreeLinkNode *pre = &dummy_node;
            for(TreeLinkNode *it = start; it != NULL; it = it->next){
                if(it->left){
                    pre->next = it->left;
                    pre = pre->next;
                }
                if(it->right){
                    pre->next = it->right;
                    pre = pre->next;
                }
            }
        }
    }
};
