//Swap Nodes in Pairs

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
        ListNode* swapPairs(ListNode* head) {
            // If list is empty or has only one node
            if (!head || !head->next) {
                return head;
            }
            
            // Initialize pointers
            ListNode* dummy = new ListNode(0); // Dummy node to handle edge cases
            dummy->next = head;
            ListNode* prev = dummy;
            ListNode* curr = head;
            
            while (curr && curr->next) {
                // Nodes to be swapped
                ListNode* first = curr;
                ListNode* second = curr->next;
                
                // Swapping
                prev->next = second;        // Connect previous node to second node
                first->next = second->next; // Connect first node to node after second
                second->next = first;       // Connect second node to first node
                
                // Move pointers
                prev = first;
                curr = first->next;
            }
            
            // Get the new head
            ListNode* newHead = dummy->next;
            delete dummy;
            return newHead;
        }
    };