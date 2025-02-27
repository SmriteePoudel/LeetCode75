//Maximum Level Sum of Binary Tree
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

// Note: TreeNode is already defined in the precompiled headers
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int maxSum = INT_MIN;
        int maxLevel = 0;
        int currLevel = 0;
        
        while (!q.empty()) {
            currLevel++;
            int size = q.size();
            int levelSum = 0;
            
            // Process all nodes at current level
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                levelSum += node->val;
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            // Update max sum and level if current level has larger sum
            if (levelSum > maxSum) {
                maxSum = levelSum;
                maxLevel = currLevel;
            }
        }
        
        return maxLevel;
    }
};