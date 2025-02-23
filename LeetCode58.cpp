//Construct Binary Tree from Preorder and Postorder Traversal

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
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
            // Create index map for postorder traversal
            unordered_map<int, int> postMap;
            for (int i = 0; i < postorder.size(); i++) {
                postMap[postorder[i]] = i;
            }
            
            return buildTree(preorder, 0, preorder.size() - 1, 
                            postorder, 0, postorder.size() - 1, postMap);
        }
        
    private:
        TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd,
                           vector<int>& postorder, int postStart, int postEnd,
                           unordered_map<int, int>& postMap) {
            if (preStart > preEnd) {
                return nullptr;
            }
            
            // Create root node from first element of preorder
            TreeNode* root = new TreeNode(preorder[preStart]);
            
            // If only one node left
            if (preStart == preEnd) {
                return root;
            }
            
            // Find the index of left child in postorder traversal
            int leftRootVal = preorder[preStart + 1];
            int leftRootPostIndex = postMap[leftRootVal];
            
            // Calculate size of left subtree
            int leftSubtreeSize = leftRootPostIndex - postStart + 1;
            
            // Recursively construct left and right subtrees
            root->left = buildTree(preorder, preStart + 1, preStart + leftSubtreeSize,
                                 postorder, postStart, leftRootPostIndex,
                                 postMap);
            
            root->right = buildTree(preorder, preStart + leftSubtreeSize + 1, preEnd,
                                  postorder, leftRootPostIndex + 1, postEnd - 1,
                                  postMap);
            
            return root;
        }
    };