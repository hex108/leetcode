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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        ListNode *cur = head, *next = cur; 

        if(head == NULL)
            return NULL;

        for(int i = 0; i < k ; i ++){
            next = next->next;
            // Case: K >= 'the size of the link list'.
            if(next == NULL){
                next = cur;
            }
        }

        // Case: cur and next point to the same node.
        if(cur == next)
            return head;

        while(next->next != NULL){
            next = next->next;
            cur = cur->next;
        }

        next->next = head;
        head = cur->next;
        cur->next = NULL;
        
        return head;
    }
};
