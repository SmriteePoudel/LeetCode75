//Increasing Triplet Subsequence
//Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

class Solution {
    public:
        bool increasingTriplet(vector<int>& nums) {
            // Edge case: if array has less than 3 elements, return false
            if (nums.size() < 3) return false;
            
            // Initialize first and second numbers to maximum possible value
            int first = INT_MAX;  // Smallest number seen so far
            int second = INT_MAX; // Second smallest number seen so far
            
            // Iterate through the array once
            for (int num : nums) {
                // If current number is smaller than or equal to first, update first
                if (num <= first) {
                    first = num;
                }
                // If current number is greater than first but smaller than or equal to second, update second
                else if (num <= second) {
                    second = num;
                }
                // If current number is greater than both first and second, we found our triplet
                else {
                    return true;
                }
            }
            
            // If we haven't found a valid triplet, return false
            return false;
        }
    };