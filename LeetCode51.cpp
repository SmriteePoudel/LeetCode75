//Recover a Tree From Preorder Traversal

class Solution {
    public:
        TreeNode* recoverFromPreorder(string traversal) {
            vector<pair<int, int>> nodes; // pairs of (depth, value)
            int i = 0;
            
            // Parse the input string
            while (i < traversal.length()) {
                int depth = 0;
                while (i < traversal.length() && traversal[i] == '-') {
                    depth++;
                    i++;
                }
                
                int value = 0;
                while (i < traversal.length() && isdigit(traversal[i])) {
                    value = value * 10 + (traversal[i] - '0');
                    i++;
                }
                
                nodes.push_back({depth, value});
            }
            
            // Stack to keep track of nodes at different depths
            vector<TreeNode*> stack;
            TreeNode* root = new TreeNode(nodes[0].second);
            stack.push_back(root);
            
            // Process each node
            for (int i = 1; i < nodes.size(); i++) {
                int depth = nodes[i].first;
                TreeNode* node = new TreeNode(nodes[i].second);
                
                // Pop nodes from stack until we find the parent
                while (stack.size() > depth) {
                    stack.pop_back();
                }
                
                // Connect the new node to its parent
                TreeNode* parent = stack.back();
                if (!parent->left) {
                    parent->left = node;
                } else {
                    parent->right = node;
                }
                
                stack.push_back(node);
            }
            
            return root;
        }
    };