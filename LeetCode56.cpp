//Remove Nth Node From End of List
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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            // Handle edge case where list is empty
            if (!head) return nullptr;
            
            // Create a dummy node to handle edge case of removing head
            ListNode* dummy = new ListNode(0);
            dummy->next = head;
            
            ListNode* fast = dummy;
            ListNode* slow = dummy;
            
            // Move fast pointer n nodes ahead
            for (int i = 0; i < n; i++) {
                fast = fast->next;
            }
            
            // Move both pointers until fast reaches the end
            while (fast->next) {
                fast = fast->next;
                slow = slow->next;
            }
            
            // Remove the nth node
            ListNode* toDelete = slow->next;
            slow->next = slow->next->next;
            delete toDelete;
            
            // Get the head of the modified list
            ListNode* result = dummy->next;
            delete dummy;
            
            return result;
        }
    };