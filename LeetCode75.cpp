//Length of Longest Fibonacci Subsequence

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int lenLongestFibSubseq(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> index; // Maps value to its index
    
    // Build the index map for fast lookup
    for (int i = 0; i < n; i++) {
        index[arr[i]] = i;
    }
    
    int maxLen = 0;
    // dp[i][j] represents the length of Fibonacci subsequence ending with arr[i] and arr[j]
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    // Initialize dp with at least 2 elements (the pair itself)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            dp[i][j] = 2;
        }
    }
    
    // Check all pairs as potential second-to-last and last elements
    for (int j = 0; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
            // Calculate what the preceding element would be in a Fibonacci sequence
            int prev = arr[j] - arr[k];
            
            // Skip if prev is non-positive or larger than arr[j] (invalid for Fibonacci-like sequence)
            if (prev >= arr[j] || prev <= 0) continue;
            
            // Check if prev exists in our array
            if (index.find(prev) != index.end()) {
                int i = index[prev];
                if (i < j) { // Ensure the correct order
                    // Extend the sequence by adding arr[k]
                    dp[j][k] = dp[i][j] + 1;
                    maxLen = max(maxLen, dp[j][k]);
                }
            }
        }
    }
    
    // Return 0 if no sequence of length >= 3 found
    return maxLen >= 3 ? maxLen : 0;
}

int main() {
    // Example 1
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << "Example 1 Output: " << lenLongestFibSubseq(arr1) << endl;
    
    // Example 2
    vector<int> arr2 = {1, 3, 7, 11, 12, 14, 18};
    cout << "Example 2 Output: " << lenLongestFibSubseq(arr2) << endl;
    
    return 0;
}