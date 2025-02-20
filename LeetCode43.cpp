//Longest Subarray of 1's After Deleting One Element
class Solution {
    public:
        int longestSubarray(vector<int>& nums) {
            int n = nums.size();
            int maxLength = 0;
            int start = 0;
            int zeroCount = 0;
            
            // Handle edge cases
            if (n == 1) return 0;
            
            // Use sliding window approach
            for (int end = 0; end < n; end++) {
                // Count zeros in current window
                if (nums[end] == 0) {
                    zeroCount++;
                }
                
                // If we have more than one zero, shrink window
                while (zeroCount > 1) {
                    if (nums[start] == 0) {
                        zeroCount--;
                    }
                    start++;
                }
                
                // Update max length (subtract 1 to account for mandatory deletion)
                maxLength = max(maxLength, end - start);
            }
            
            // If no zeros found, we must delete one element
            if (zeroCount == 0) {
                return n - 1;
            }
            
            return maxLength;
        }
    };
