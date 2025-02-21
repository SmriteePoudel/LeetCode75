//Odd Even Linked List
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
        ListNode* oddEvenList(ListNode* head) {
            // Handle empty list or lists with 1 or 2 nodes
            if (!head || !head->next || !head->next->next) {
                return head;
            }
            
            // Initialize pointers
            ListNode* odd = head;           // Points to odd indexed nodes
            ListNode* even = head->next;    // Points to even indexed nodes
            ListNode* evenHead = even;      // Keeps track of the start of even nodes
            
            // Traverse the list and rearrange nodes
            while (even && even->next) {
                // Connect odd nodes
                odd->next = even->next;
                odd = odd->next;
                
                // Connect even nodes
                even->next = odd->next;
                even = even->next;
            }
            
            // Connect the end of odd list to the start of even list
            odd->next = evenHead;
            
            return head;
        }
    };