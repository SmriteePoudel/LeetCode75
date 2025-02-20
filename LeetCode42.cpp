//Max Consecutive Ones III
class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            // Initialize variables
            int maxOnes = 0;  // To store the maximum length
            int zeroCount = 0;  // Count of zeros in current window
            int left = 0;  // Left pointer of window
            
            // Iterate through the array with right pointer
            for (int right = 0; right < nums.size(); right++) {
                // If we encounter a zero, increment zeroCount
                if (nums[right] == 0) {
                    zeroCount++;
                }
                
                // If number of zeros in window exceeds k,
                // shrink window from left until we have valid count
                while (zeroCount > k) {
                    if (nums[left] == 0) {
                        zeroCount--;
                    }
                    left++;
                }
                
                // Update maxOnes if current window is larger
                maxOnes = max(maxOnes, right - left + 1);
            }
            
            return maxOnes;
        }
    };