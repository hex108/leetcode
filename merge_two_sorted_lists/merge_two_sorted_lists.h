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
    // Assume they are ascending list.
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;

        ListNode *head = NULL, *tail = NULL;
        if(l1->val <= l2->val){
            head = tail = l1; 
            l1 = l1->next;
        }else{
            head = tail = l2; 
            l2 = l2->next;
        }

        while(l1 && l2){
            if(l1->val <= l2->val){
                tail->next = l1;
                l1 = l1->next;
            }else{
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        if(l1)
            tail->next = l1;
        else
            tail->next = l2;

        return head;
    }
};
