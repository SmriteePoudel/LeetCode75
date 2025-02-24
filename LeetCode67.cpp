//Maximum Twin Sum of a Linked List

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
        int pairSum(ListNode* head) {
            // Step 1: Find the middle of the linked list using slow and fast pointers
            ListNode* slow = head;
            ListNode* fast = head;
            
            while (fast != nullptr && fast->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
            }
            
            // Step 2: Reverse the second half of the linked list
            ListNode* prev = nullptr;
            ListNode* curr = slow;
            ListNode* next = nullptr;
            
            while (curr != nullptr) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            
            // Step 3: Find the maximum twin sum
            int maxTwinSum = 0;
            ListNode* firstHalf = head;
            ListNode* secondHalf = prev; // prev is now the head of the reversed second half
            
            while (secondHalf != nullptr) {
                maxTwinSum = max(maxTwinSum, firstHalf->val + secondHalf->val);
                firstHalf = firstHalf->next;
                secondHalf = secondHalf->next;
            }
            
            return maxTwinSum;
        }
    };