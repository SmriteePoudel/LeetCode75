//Move Zeroes
//Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.


class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            // Initialize the position where we should place the next non-zero element
            int nonZeroPos = 0;
            
            // First pass: Move all non-zero elements to the front
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] != 0) {
                    nums[nonZeroPos] = nums[i];
                    nonZeroPos++;
                }
            }
            
            // Second pass: Fill the remaining positions with zeros
            while (nonZeroPos < nums.size()) {
                nums[nonZeroPos] = 0;
                nonZeroPos++;
            }
        }
    };