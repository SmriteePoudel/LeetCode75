//Maximum Average Subarray I
//You are given an integer array nums consisting of n elements, and an integer k.

//Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

class Solution {
    public:
        double findMaxAverage(vector<int>& nums, int k) {
            // Calculate sum of first k elements
            double sum = 0;
            for (int i = 0; i < k; i++) {
                sum += nums[i];
            }
            
            // Initialize maxSum with current sum
            double maxSum = sum;
            
            // Slide the window
            for (int i = k; i < nums.size(); i++) {
                // Add current element and remove element k positions behind
                sum = sum + nums[i] - nums[i - k];
                // Update maxSum if current sum is greater
                maxSum = max(maxSum, sum);
            }
            
            // Return maximum average
            return maxSum / k;
        }
    };