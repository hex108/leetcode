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
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode dummy_head(0);
        dummy_head.next = head;

        ListNode *pre = head, *pre_tail = &dummy_head;
        ListNode *cur, *next;
        while(pre && pre->next){
            cur = pre->next;
            next = cur->next;

            cur->next = pre;
            pre_tail->next = cur;
            pre_tail = pre;

            pre = next;
        }
        pre_tail->next = pre;

        return dummy_head.next;
    }
};
