// leetcode
// https://leetcode.com/problems/sort-list/

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
    ListNode* findMiddle(ListNode* head){
        auto slow = head, fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* a, ListNode* b){
        
        auto head = new ListNode(-1);
        auto it = head;

        while(a != NULL && b != NULL){
            if(a->val <= b->val){
                it->next = a;
                a= a->next;
            }else{
                it->next = b;
                b= b->next;                
            }
                it = it->next;
        }

        if(a != NULL){
            it->next = a;           
        }
        else{
            it->next = b;            
        }
        return head->next;
    }

    ListNode* mergeSort(ListNode* head){
        if(head == NULL || head->next == NULL) return head;

        auto middle = findMiddle(head);
        auto leftHead = head , rightHead = middle->next;
        middle->next = NULL;
        leftHead = mergeSort(leftHead);
        rightHead = mergeSort(rightHead);
        return merge(leftHead, rightHead);
    }
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
        // auto ogHead = head;
        // vector<int> ans;
        // while(ogHead != NULL){
        //     ans.push_back(ogHead->val);
        //     ogHead = ogHead->next;
        // }
        // sort(ans.begin(), ans.end());
        // ogHead = head;
        // int i = 0;
        // while(ogHead != NULL){
        //     ogHead->val= ans[i];
        //     ogHead = ogHead->next;
        //     i++;
        // }
        // return head;
    }
};