// https://leetcode.com/problems/intersection-of-two-linked-lists/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto aNode = headA;
        auto bNode = headB;

        if(aNode == NULL || bNode == NULL) return NULL;
        
        // O(N1 + N2)
        while(aNode != bNode){
            // move to next 
            aNode= aNode->next;
            bNode= bNode->next;

            // found intersection || both are pointing to NULL
            if(aNode == bNode) return aNode;
            
            // crossing the heads
            if(aNode == NULL){
                aNode = headB;
            }
            if(bNode == NULL){
                bNode = headA;
            }
        }
        return aNode;


        // TC: O(len of A * tc of map) + O(len of B * tc of map)
        // SC: O(len of A);
        // unordered_map<ListNode*, int> uomap;

        // while(aNode != NULL){
        //     uomap[aNode] = 1;
        //     aNode = aNode->next;
        // }

        // while(bNode != NULL){
        //     if(uomap.find(bNode) != uomap.end()) return bNode;
        //     bNode = bNode->next;
        // }
        // return NULL;

        // O(N^2)
        // while(aNode != NULL ){
        //     while(bNode != NULL){
        //         if(aNode == bNode) 
        //             return aNode;
        //         bNode = bNode->next;
        //     }
        //     aNode = aNode->next;
        //     bNode = headB;
        // }
        // return NULL;
    }
};