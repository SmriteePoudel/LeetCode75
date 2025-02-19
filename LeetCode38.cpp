//Find Pivot index


#include <vector>
#include <numeric>  // For accumulate

class Solution {
public:
    int pivotIndex(std::vector<int>& nums) {
        // Calculate total sum of the array
        int totalSum = std::accumulate(nums.begin(), nums.end(), 0);
        
        // Keep track of the running sum from left side
        int leftSum = 0;
        
        // Iterate through each index to check if it's a pivot
        for (int i = 0; i < nums.size(); i++) {
            // Right sum can be calculated by subtracting leftSum and current number from totalSum
            int rightSum = totalSum - leftSum - nums[i];
            
            // Check if this index is a pivot
            if (leftSum == rightSum) {
                return i;
            }
            
            // Add current number to leftSum before moving to next index
            leftSum += nums[i];
        }
        
        // If no pivot index is found, return -1
        return -1;
    }
};