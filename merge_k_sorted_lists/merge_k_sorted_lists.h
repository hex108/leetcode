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
    void erase_null_list(vector<ListNode *> &lists){
        for(size_t i = 0; i < lists.size(); ){
            if(lists[i] == NULL)
                lists.erase(lists.begin() + i);
            else
                i ++;
        }
    }

    void swap(vector<ListNode *> &lists, size_t i, size_t j){
        ListNode *tmp = lists[i];
        lists[i] = lists[j];
        lists[j] = tmp;
    }
    
    size_t get_min(vector<ListNode *> &lists, size_t i, size_t j){
        if(lists[i]->val < lists[j]->val)
            return i;
        else
            return j;
    }

    void make_min_heap(vector<ListNode *> &lists){
        int tail = lists.size() - 1;
        int i = (tail - 1) / 2;
        int min = i;

        if(2 * i + 1 <= tail)
            min = get_min(lists, min, 2 * i + 1);
            
        if(2 * i + 2 <= tail)
            min = get_min(lists, min, 2 * i + 2);
            
        if(i != min)
            swap(lists, i, min);

        i --;

        while(i >= 0){
            min = get_min(lists, 2 * i + 1, 2 * i + 2);
            if(lists[i]->val > lists[min]->val){
                swap(lists, i, min);
                adjust_min_heap(lists, min);
            }
            i --;
        }
    }

    void adjust_min_heap(vector<ListNode *> &lists, size_t start){
        size_t tail = lists.size() - 1;
        size_t end = (tail - 1) / 2;

        for(size_t i = start; i <= end; ){
            size_t min = i;

            if(2 * i + 1 <= tail)
                min = get_min(lists, min, 2 * i + 1);

            if(2 * i + 2 <= tail)
                min = get_min(lists, min, 2 * i + 2);

            if(i != min){
                swap(lists, i, min);
                i = min;
            }else{
                return;
            }
        }
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        erase_null_list(lists); 
        if(lists.empty())
            return NULL;

        ListNode *head, *tail;

        make_min_heap(lists);
        head = tail = lists[0];
        lists[0] = lists[0]->next;

        while(lists.size() > 1){
            if(lists[0] == NULL){
                lists[0] = lists[lists.size() - 1];
                lists.erase(lists.begin() + lists.size() - 1);
            }

            adjust_min_heap(lists, 0);
            
            tail->next = lists[0];
            tail = tail->next;
            lists[0] = lists[0]->next;
        }

        tail->next = lists[0];

        return head;
    }
};
