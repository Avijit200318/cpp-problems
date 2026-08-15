// Linked List Cycle

// using map or hashmap
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         map<ListNode*, int> mpp;
//         ListNode* x = head;
//         while(x != nullptr){
//             if(mpp.find(x) != mpp.end()){
//                 return true;
//             }
//             mpp[x] = 1;
//             x = x->next;
//         }
//         return false;
//     }
// };


// slow and fast pointer method
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;

        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow) return true;
        }
        return false;
    }
};