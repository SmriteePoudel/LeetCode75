//Binary Tree Right Side View

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
        // Approach 1: BFS (Level Order Traversal)
        vector<int> rightSideView(TreeNode* root) {
            vector<int> result;
            if (!root) return result;
            
            queue<TreeNode*> q;
            q.push(root);
            
            while (!q.empty()) {
                int levelSize = q.size();
                
                for (int i = 0; i < levelSize; i++) {
                    TreeNode* node = q.front();
                    q.pop();
                    
                    // If this is the last node in the current level, add it to result
                    if (i == levelSize - 1) {
                        result.push_back(node->val);
                    }
                    
                    // Add child nodes to the queue
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
            }
            
            return result;
        }
        
        // Approach 2: DFS (Preorder with right child first)
        vector<int> rightSideViewDFS(TreeNode* root) {
            vector<int> result;
            dfs(root, 0, result);
            return result;
        }
        
        void dfs(TreeNode* node, int level, vector<int>& result) {
            if (!node) return;
            
            // If this is the first node we're seeing at this level
            if (level == result.size()) {
                result.push_back(node->val);
            }
            
            // Visit right child first, then left
            dfs(node->right, level + 1, result);
            dfs(node->left, level + 1, result);
        }
    };