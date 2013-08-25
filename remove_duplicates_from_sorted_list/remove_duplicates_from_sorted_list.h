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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *cur = head, *next;

        while(cur != NULL){
            next = cur->next;
            while(next != NULL && next->val == cur->val){
                next = next->next;
            }
            cur->next = next;
            cur = next;
        }

        return head;
    }
};
