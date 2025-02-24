//Most Profitable Path in a tree 
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    // Find path from Bob to root and store timing
    bool findBobPath(int curr, int parent, vector<vector<int>>& graph, vector<int>& path, vector<bool>& visited) {
        visited[curr] = true;
        path.push_back(curr);
        
        if (curr == 0) return true;
        
        for (int next : graph[curr]) {
            if (!visited[next] && findBobPath(next, curr, graph, path, visited)) {
                return true;
            }
        }
        
        path.pop_back();
        return false;
    }

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        
        // Build graph
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        // Find Bob's path to root
        vector<int> bobPath;
        vector<bool> visited(n, false);
        findBobPath(bob, -1, graph, bobPath, visited);
        
        // Mark Bob's timing at each node
        vector<int> bobTime(n, n);
        for (int i = 0; i < bobPath.size(); i++) {
            bobTime[bobPath[i]] = i;
        }
        
        // DFS for Alice's path
        int maxIncome = INT_MIN;
        
        function<void(int, int, int, long long)> dfs = [&](int node, int parent, int time, long long income) {
            // Calculate current node's contribution
            long long curr_amount = amount[node];
            
            if (time < bobTime[node]) {
                // Alice reaches before Bob
                curr_amount = amount[node];
            } else if (time == bobTime[node]) {
                // Alice and Bob reach simultaneously
                curr_amount = amount[node] / 2;
            } else if (time > bobTime[node]) {
                // Bob reaches before Alice
                curr_amount = 0;
            }
            
            income += curr_amount;
            
            // Check if it's a leaf
            bool isLeaf = true;
            for (int next : graph[node]) {
                if (next != parent) {
                    isLeaf = false;
                    dfs(next, node, time + 1, income);
                }
            }
            
            if (isLeaf) {
                maxIncome = max(maxIncome, (int)income);
            }
        };
        
        dfs(0, -1, 0, 0);
        
        return maxIncome;
    }
};