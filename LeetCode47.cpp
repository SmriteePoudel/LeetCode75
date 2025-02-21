//Delete the Middle Node of a Linked List

class Solution {
    public:
        ListNode* deleteMiddle(ListNode* head) {
            // If list is empty or has only one node
            if (head == nullptr || head->next == nullptr)
                return nullptr;
            
            // If list has only two nodes
            if (head->next->next == nullptr) {
                head->next = nullptr;
                return head;
            }
            
            // Use slow and fast pointer technique
            ListNode* slow = head;
            ListNode* fast = head;
            ListNode* prev = nullptr;
            
            // Find middle node
            while (fast != nullptr && fast->next != nullptr) {
                fast = fast->next->next;
                prev = slow;
                slow = slow->next;
            }
            
            // Delete middle node
            prev->next = slow->next;
            delete slow;
            
            return head;
        }
    };