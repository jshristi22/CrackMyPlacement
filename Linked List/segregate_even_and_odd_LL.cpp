
// https://leetcode.com/problems/odd-even-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)       return head;
        auto first = head;
        auto second = head->next;
        auto temp = head->next;
        while(first->next != NULL && second->next != NULL){           
            first->next = second->next;
            first = second->next;

            second->next = first->next;
            second = first->next;
        }
        first->next = temp;
        return head;
    }
};