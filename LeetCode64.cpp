//Remove Duplicates from Sorted Array

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            if (nums.empty()) return 0;
            
            // Position where we'll place the next unique element
            int writePos = 1;
            
            // Start from second element since first is always unique
            for (int readPos = 1; readPos < nums.size(); readPos++) {
                // If current element is different from previous element
                if (nums[readPos] != nums[readPos - 1]) {
                    nums[writePos] = nums[readPos];
                    writePos++;
                }
            }
            
            return writePos;
        }
    };