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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    // Range is [start, end) exclude end.
    TreeNode *convert_to_bst(ListNode *start, ListNode *end){
        if(start == end)
            return NULL;
        
        if(start->next == end){
            TreeNode *node = new TreeNode(start->val);
            return node;
        }

        ListNode *mid = get_mid(start, end);
        TreeNode *root = new TreeNode(mid->val);  
        TreeNode *left = convert_to_bst(start, mid);
        TreeNode *right = convert_to_bst(mid->next, end);

        root->left = left;
        root->right = right;

        return root;
    }

    // Range is [start, end) exclude end.
    ListNode *get_mid(ListNode *start, ListNode *end){
        // use slow and fast pointer to find the middle
        ListNode *slow = start, *fast = start;
        while(fast != end && fast->next != end){
            slow = slow->next;
            fast = fast->next->next; 
        }

        return slow;
    }

public:
    TreeNode *sortedListToBST(ListNode *head) {
        return convert_to_bst(head, NULL); 
    }
};
