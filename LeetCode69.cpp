//Number of Sub-arrays With Odd Sum

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        
        long long oddCount = 0;   // Count of subarrays with odd sum
        long long evenCount = 1;  // Count of subarrays with even sum (including empty subarray)
        
        long long prefixSum = 0;
        long long result = 0;
        
        for (int num : arr) {
            // Update prefix sum
            prefixSum += num;
            
            // If current prefix sum is odd
            if (prefixSum % 2 == 1) {
                // Add number of even prefix sums seen so far
                result = (result + evenCount) % MOD;
                // Increment count of odd prefix sums
                oddCount = (oddCount + 1) % MOD;
            } else { // If current prefix sum is even
                // Add number of odd prefix sums seen so far
                result = (result + oddCount) % MOD;
                // Increment count of even prefix sums
                evenCount = (evenCount + 1) % MOD;
            }
        }
        
        return result;
    }
};

