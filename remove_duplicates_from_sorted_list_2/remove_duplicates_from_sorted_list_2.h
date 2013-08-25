/* Notes: It is a problem that I came across when interviewing one year ago.
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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode dummy_head(0);
        dummy_head.next = head;

        ListNode *pre = &dummy_head, *cur = head, *next;

        while(cur != NULL){
            next = cur->next;
            while(next != NULL && next->val == cur->val){
                next = next->next;
            }

            // The value of nodes in the range [cur, next) are same as cur's.
            if(cur->next != next){
                pre->next = next;
            }else{
                pre = cur;
            }

            cur = next;
        }

        return dummy_head.next;
    }
};
