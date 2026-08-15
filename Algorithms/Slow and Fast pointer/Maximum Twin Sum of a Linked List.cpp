// Maximum Twin Sum of a Linked List

// Input: head = [5,4,2,1]
// Output: 6
// Explanation:
// Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin sum = 6.
// There are no other nodes with twins in the linked list.
// Thus, the maximum twin sum of the linked list is 6. 
// Example 2:


// Input: head = [4,2,2,3]
// Output: 7
// Explanation:
// The nodes with twins present in this linked list are:
// - Node 0 is the twin of node 3 having a twin sum of 4 + 3 = 7.
// - Node 1 is the twin of node 2 having a twin sum of 2 + 2 = 4.
// Thus, the maximum twin sum of the linked list is max(7, 4) = 7. 

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

// class Solution {
// public:
//     int pairSum(ListNode* head) {
//         vector<int> ans;
//         ListNode *x = head;

//         while(x != nullptr){
//             ans.push_back(x->val);
//             x = x->next;
//         }

//         int left = 0, right = ans.size()-1;
//         int maxSum = 0;

//         while(left < right){
//             maxSum = max(maxSum, ans[left] + ans[right]);
//             left++;
//             right--;
//         }

//         return maxSum;
//     }
// };

class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head, *prev = nullptr, *temp;

        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        // after that since our linked list size is even the slow value will be the right side array begening and prev will be the left side array end

        int maxSum = 0;
        while(slow != nullptr){
            maxSum = max(maxSum, slow->val + prev->val);
            slow = slow->next;
            prev = prev->next;
        }

        return maxSum;
    }
};