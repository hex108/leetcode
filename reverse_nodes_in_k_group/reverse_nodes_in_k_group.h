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
class Solution {
    bool greater_than(ListNode *start, int k){
        int count = 0;

        for(ListNode *it = start; it != NULL; it = it->next){
            count ++;
            if(count >= k)
                break;
        }
        
        return count >= k;
    }

    ListNode *reverse(ListNode *pre_head, ListNode *start, int k){
        k --;

        ListNode *pre = start, *cur = start->next, *next = NULL;
        while(k && cur != NULL){
            next = cur->next; 

            cur->next = pre;
            pre = cur;
            cur = next;

            k --;
        }
        
        ListNode *tail = pre_head->next;
        pre_head->next = pre;
        tail->next = cur; 

        return tail;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(k <= 1 || head == NULL)
            return head;

        ListNode dummy_head(0);
        dummy_head.next = head;

        ListNode *pre_head = &dummy_head;
        while(1){
            if(greater_than(pre_head->next, k) == false)
                break;
            
            pre_head = reverse(pre_head, pre_head->next, k);
        }

        return dummy_head.next;
    }
};
