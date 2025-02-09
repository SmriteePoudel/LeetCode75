 //Count Number of Bad Pairs
//You are given a 0-indexed integer array nums. A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].
//Return the total number of bad pairs in nums.


#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        // For a pair (i,j) to be good: j - i = nums[j] - nums[i]
        // Rearranging: nums[j] - j = nums[i] - i
        // So if nums[j] - j != nums[i] - i, it's a bad pair
        
        int n = nums.size();
        unordered_map<long long, long long> count;
        
        // Calculate nums[i] - i for each index and store frequency
        for (int i = 0; i < n; i++) {
            long long diff = (long long)nums[i] - i;
            count[diff]++;
        }
        
        // Calculate total pairs and subtract good pairs
        long long totalPairs = (long long)n * (n - 1) / 2;
        long long goodPairs = 0;
        
        // For each group of numbers with same difference,
        // calculate number of good pairs within that group
        for (auto& pair : count) {
            long long freq = pair.second;
            goodPairs += (freq * (freq - 1)) / 2;
        }
        
        // Return total pairs minus good pairs
        return totalPairs - goodPairs;
    }
};