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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head == NULL)
            return NULL;

        ListNode *cur = head, *next = head;
        
        for(int i = 0; i < n; i ++)
            next = next->next;

        // remove the first node
        if(next == NULL)
            return head->next;

        while(next->next != NULL){
            next = next->next;
            cur = cur->next;
        }

        cur->next = cur->next->next;

        return head;
    }
};
