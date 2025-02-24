//Delete Node in a BST

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        TreeNode* deleteNode(TreeNode* root, int key) {
            // Base case: If tree is empty
            if (root == nullptr) return nullptr;
            
            // Search for the node to be deleted
            if (key < root->val) {
                // The key to be deleted is in the left subtree
                root->left = deleteNode(root->left, key);
            } else if (key > root->val) {
                // The key to be deleted is in the right subtree
                root->right = deleteNode(root->right, key);
            } else {
                // Current node is the one to be deleted
                
                // Case 1: Node with no children (leaf node)
                if (root->left == nullptr && root->right == nullptr) {
                    delete root;
                    return nullptr;
                }
                
                // Case 2: Node with only one child
                else if (root->left == nullptr) {
                    TreeNode* temp = root->right;
                    delete root;
                    return temp;
                } else if (root->right == nullptr) {
                    TreeNode* temp = root->left;
                    delete root;
                    return temp;
                }
                
                // Case 3: Node with two children
                // Find the inorder successor (smallest node in right subtree)
                TreeNode* temp = findMin(root->right);
                
                // Copy the inorder successor's value to the current node
                root->val = temp->val;
                
                // Delete the inorder successor
                root->right = deleteNode(root->right, temp->val);
            }
            
            return root;
        }
        
    private:
        // Helper function to find the minimum value node in a BST
        TreeNode* findMin(TreeNode* node) {
            TreeNode* current = node;
            
            // Loop to find the leftmost leaf
            while (current && current->left != nullptr) {
                current = current->left;
            }
            
            return current;
        }
    };