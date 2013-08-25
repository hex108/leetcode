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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    void insert_after(ListNode *&n1, ListNode *&n2){
        if(n1 == NULL){
            n1 = n2;
        }else{
            n1->next = n2;
            n1 = n2;
        }
    }
public:
    ListNode *partition(ListNode *head, int x) {
        // The first and last node whose value is less than x;
        ListNode *first_lt_node = NULL, *last_lt_node = NULL;
        // The first and last node whose value is greater than or equal to x;
        ListNode *first_ge_node = NULL, *last_ge_node = NULL; 

        ListNode *cur = head, *next;

        while(cur != NULL){
            next = cur->next;
            if(cur->val < x){
                insert_after(last_lt_node, cur);
                if(first_lt_node == NULL)
                    first_lt_node = cur;

                while(next != NULL && next->val < x){
                    last_lt_node = next;
                    next = next->next;
                }
            }else{
                insert_after(last_ge_node, cur);
                if(first_ge_node == NULL)
                    first_ge_node = cur;

                while(next != NULL && next->val >= x){
                    last_ge_node = next;
                    next = next->next;
                }
            }
            cur = next;
        }

        if(last_ge_node != NULL){
            last_ge_node->next = NULL;
        }

        if(last_lt_node != NULL){
            last_lt_node->next = first_ge_node;
            return first_lt_node;
        }else{
            return first_ge_node;
        }
    }
};
