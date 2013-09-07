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
    int add(int a, int b, int &addtion_carry){
        int result = a + b + addtion_carry;
        if(result >= 10){
            result = result - 10;
            addtion_carry = 1;
        }else
            addtion_carry = 0;

        return result;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy_head(0);
        ListNode *tail = &dummy_head;
    
        int addtion_carry = 0;
        while(l1 && l2){
            int result = add(l1->val, l2->val, addtion_carry);

            ListNode *new_node = new ListNode(result);
            tail->next = new_node;
            tail = new_node;

            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode *remain = l1 != NULL? l1 : l2;
        while(remain){
            int result = add(remain->val, 0, addtion_carry);

            ListNode *new_node = new ListNode(result);
            tail->next = new_node;
            tail = new_node;
            
            remain = remain->next; 
        }

        if(addtion_carry){
            ListNode *new_node = new ListNode(1);
            tail->next = new_node;
        }

        return dummy_head.next;
    }
};
