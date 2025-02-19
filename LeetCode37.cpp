//Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> result;
            // We need at least 3 numbers to form a triplet
            if (nums.size() < 3) return result;
            
            // Sort the array to handle duplicates and use two-pointer technique
            sort(nums.begin(), nums.end());
            
            // Fix the first element and find the other two using two pointers
            for (int i = 0; i < nums.size() - 2; i++) {
                // Skip duplicates for i
                if (i > 0 && nums[i] == nums[i-1]) continue;
                
                int left = i + 1;
                int right = nums.size() - 1;
                
                while (left < right) {
                    int sum = nums[i] + nums[left] + nums[right];
                    
                    if (sum == 0) {
                        // Found a triplet
                        result.push_back({nums[i], nums[left], nums[right]});
                        
                        // Skip duplicates for left
                        while (left < right && nums[left] == nums[left+1]) left++;
                        // Skip duplicates for right
                        while (left < right && nums[right] == nums[right-1]) right--;
                        
                        left++;
                        right--;
                    }
                    else if (sum < 0) {
                        // Sum is too small, increment left
                        left++;
                    }
                    else {
                        // Sum is too large, decrement right
                        right--;
                    }
                }
            }
            
            return result;
        }
    };