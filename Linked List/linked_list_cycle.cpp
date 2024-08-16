// https://leetcode.com/problems/linked-list-cycle/submissions/1355394340/

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
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        auto slow = head;
        auto fast = head;

        while(slow != NULL && fast != NULL && fast->next != NULL){
            slow = slow->next;  // taking 1 step at a time.
            fast = fast->next->next; //taking 2 steps at a time.

            if(slow == fast) return true;
        }
        return false;


        // TC: O(N * 2(1))
        // SC: O(n)
        // map<ListNode*, int> umap;
        // auto temp = head;
        // while(temp != NULL){
        //     if(umap.find(temp) != umap.end()){
        //         // already visited;
        //         return true;
        //     }
        //     umap[temp] = 1; // mark as visited;
        //     temp = temp->next;
        // }
        // return false;
    }
};