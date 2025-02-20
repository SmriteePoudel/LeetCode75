//Find Unique Binary String

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string result;
        
        // Use Cantor's diagonal argument
        // Take the opposite of each character at position i from nums[i]
        for (int i = 0; i < nums.size(); i++) {
            // If the current bit is '0', add '1', otherwise add '0'
            result += nums[i][i] == '0' ? '1' : '0';
        }
        
        return result;
    }
};