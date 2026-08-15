// Linked List Cycle II
// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         map<ListNode* , int> mpp;
//         ListNode* x = head;
//         while(x != nullptr){
//             if(mpp.find(x) != mpp.end()){
//                 return x;
//             }
//             mpp[x] = 1;
//             x = x->next;
//         }
//         return nullptr;
//     }
// };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head, *slow2 = head;

        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow) break;
        }

        if(fast == nullptr || fast->next == nullptr) return nullptr;

        while(slow2 != slow){
            slow = slow->next;
            slow2 = slow2->next;
        }
        return slow;
    }
};