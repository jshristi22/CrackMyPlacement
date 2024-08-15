
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/


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
private: 
// O(2n)
// O(1);
    ListNode* bruteForceApp(ListNode* head, int n){
        int cnt = 0;
        auto temp = head;
        
        while(temp != NULL){
            cnt++;            
            temp= temp->next;            
        }
        
        int deleteNodeIdx = cnt - n;
        
        // if head node is deleted
        if(deleteNodeIdx == 0){
            auto newHead = head->next;
            delete(head);
            return newHead;
        }

        temp = head;
        
        while(temp != NULL){
            deleteNodeIdx--;
            if(deleteNodeIdx == 0) break;
            temp= temp->next;        
        }
        
        auto delNode = temp->next;
        temp->next = temp->next->next;
        delete(delNode);       
        return head;           
    };
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;

        // return bruteForceApp(head, n);

// O(N)
// O(1)
        auto slow = head;
        auto fast = head;

        for(int i = 0; i<n; i++) fast = fast->next;

        if(fast == NULL){
            auto newHead = head->next;
            delete(head);
            return newHead;
        }

        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next; //move 2 steps
        }
        auto delNode = slow->next;
        slow->next = slow->next->next;
        delete(delNode);
        return head;
    }     
};