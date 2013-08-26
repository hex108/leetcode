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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy_head(0);
        dummy_head.next = head;

        ListNode *pre_start = &dummy_head;
        for(int i = 1; i < m; i ++)
            pre_start = pre_start->next;

        ListNode *start = pre_start->next;
        ListNode *end = start;
        for(int i = 0; i < n - m; i ++)
            end = end->next;
        
        ListNode *pre = start;
        ListNode *mid = pre->next;
        ListNode *post;

        pre_start->next = end;
        start->next = end->next;

        while(pre != end){
            post = mid->next;
            mid->next = pre;
            pre = mid;
            mid = post;
        }

        return dummy_head.next;
    }
};
