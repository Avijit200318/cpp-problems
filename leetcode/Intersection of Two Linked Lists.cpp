// Intersection of Two Linked Lists
// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.



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
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     ListNode* intersection = nullptr;
    //     unordered_map<ListNode*, int> mpp;
    //     ListNode* x = headA;
    //     while(x != nullptr){
    //         mpp[x]=1;
    //         x = x->next;
    //     }

    //     ListNode* y = headB;
    //     while(y != nullptr){
    //         if(mpp.find(y) != mpp.end()){
    //             return y;
    //         }
    //         y = y->next;
    //     }
    //     return intersection;
    // }
    ListNode *collusionPoint(ListNode *headA, ListNode *headB, int sizeA, int sizeB){
        int diff = sizeB - sizeA;
        int i = 0;
        ListNode* x = headA, *y = headB;
        while(i < diff){
            y = y->next;
            i++;
        }

        while(x != nullptr){
            if(x == y) return x;
            x = x->next;
            y = y->next;
        }
        return nullptr;
    }

    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     ListNode* intersection = nullptr;
    //     ListNode* x = headA, *y = headB;
    //     int sizeA = 0, sizeB = 0;
    //     while(x != nullptr){
    //         sizeA++;
    //         x = x->next;
    //     }

    //     while(y != nullptr){
    //         sizeB++;
    //         y = y->next;
    //     }

    //     if(sizeA > sizeB) return collusionPoint(headB, headA, sizeB, sizeA);
    //     else return collusionPoint(headA, headB, sizeA, sizeB);
    // }


// ***-----------------------------***
// when one pointer become null then set it to the head of the oposite pointer and continue this untill x and y are equal

//***--------------------------------***
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* intersection = nullptr;
        ListNode* x = headA, *y = headB;
        if(x == y) return x;
        while(x != y){
            x = x->next;
            y = y->next;
            if(x == y) return x;

            if(x == nullptr) x = headB;
            if(y == nullptr) y = headA;
        }
        return x;
    }
};
