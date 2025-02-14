//Minimum Operations to Exceed Threshold Value 

//You are given a 0-indexed integer array nums, and an integer k.
//You are allowed to perform some operations on nums, where in a single operation, you can:
//Select the two smallest integers x and y from nums.
//Remove x and y from nums.
//Insert (min(x, y) * 2 + max(x, y)) at any position in the array.

#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // Create a min heap priority queue
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        // Add all elements to the priority queue
        for (int num : nums) {
            pq.push(num);
        }
        
        int operations = 0;
        
        // Continue operations until all elements are >= k
        while (pq.size() >= 2 && pq.top() < k) {
            // Get the two smallest elements
            long long x = pq.top(); pq.pop();
            long long y = pq.top(); pq.pop();
            
            // Calculate new value and add it back to the queue
            long long newVal = min(x, y) * 2 + max(x, y);
            pq.push(newVal);
            
            operations++;
        }
        
        // Check if all remaining elements are >= k
        if (!pq.empty() && pq.top() < k) {
            return -1;  // Impossible case (though problem states it's always possible)
        }
        
        return operations;
    }
};