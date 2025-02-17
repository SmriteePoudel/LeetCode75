//Max Number of K-Sum Pairs
//You are given an integer array nums and an integer k.
//In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.
//Return the maximum number of operations you can perform on the array.


class Solution {
    public:
        int maxOperations(vector<int>& nums, int k) {
            // Use unordered_map to store frequency of each number
            unordered_map<int, int> counter;
            for (int num : nums) {
                counter[num]++;
            }
            
            int operations = 0;
            unordered_set<int> seen;
            
            // Iterate through each unique number
            for (const auto& pair : counter) {
                int num = pair.first;
                
                // Skip if we've already processed this pair
                if (seen.count(num)) {
                    continue;
                }
                
                int complement = k - num;
                seen.insert(num);
                seen.insert(complement);
                
                if (num == complement) {
                    // If number is half of k, we can make pairs from the same number
                    operations += counter[num] / 2;
                } else {
                    // For different numbers, take the minimum of their frequencies
                    auto it = counter.find(complement);
                    if (it != counter.end()) {
                        operations += min(counter[num], it->second);
                    }
                }
            }
            
            return operations;
        }
    };
    
    // Test code
    void test() {
        Solution solution;
        
        vector<vector<int>> nums = {
            {1, 2, 3, 4},
            {3, 1, 3, 4, 3}
        };
        vector<int> k = {5, 6};
        
        for (int i = 0; i < nums.size(); i++) {
            cout << "Input: nums = [";
            for (int j = 0; j < nums[i].size(); j++) {
                cout << nums[i][j];
                if (j < nums[i].size() - 1) cout << ",";
            }
            cout << "], k = " << k[i] << endl;
            cout << "Output: " << solution.maxOperations(nums[i], k[i]) << endl << endl;
        }
    }