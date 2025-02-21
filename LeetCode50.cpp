//Reverse Nodes in K-Group

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
        ListNode* reverseKGroup(ListNode* head, int k) {
            // Handle base cases
            if (!head || k == 1) return head;
            
            // Count total nodes
            int count = 0;
            ListNode* curr = head;
            while (curr) {
                count++;
                curr = curr->next;
            }
            
            // Create a dummy node
            ListNode* dummy = new ListNode(0);
            dummy->next = head;
            ListNode* prev = dummy;
            curr = head;
            
            // Process k nodes at a time
            while (count >= k) {
                curr = prev->next; // First node of current k-group
                ListNode* next = curr->next; // Second node of current k-group
                
                // Reverse k-1 links
                for (int i = 1; i < k; i++) {
                    curr->next = next->next;
                    next->next = prev->next;
                    prev->next = next;
                    next = curr->next;
                }
                
                prev = curr;
                count -= k;
            }
            
            // Get the head of modified list
            ListNode* result = dummy->next;
            delete dummy; // Free the dummy node
            return result;
        }
    };