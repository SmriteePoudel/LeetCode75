//Find Elements in a Contaminated Binary Tree

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
class FindElements {
    private:
        unordered_set<int> values;
        
        void recover(TreeNode* node, int value) {
            if (!node) return;
            
            // Recover the current node's value
            node->val = value;
            values.insert(value);
            
            // Recover left child: 2 * x + 1
            if (node->left) {
                recover(node->left, 2 * value + 1);
            }
            
            // Recover right child: 2 * x + 2
            if (node->right) {
                recover(node->right, 2 * value + 2);
            }
        }
        
    public:
        FindElements(TreeNode* root) {
            // Start recovery from root with value 0
            recover(root, 0);
        }
        
        bool find(int target) {
            return values.contains(target);
        }
    };