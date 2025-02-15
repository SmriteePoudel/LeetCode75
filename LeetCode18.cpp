//Find the Punishment Number of an Integer
//Given a positive integer n, return the punishment number of n.
//The punishment number of n is defined as the sum of the squares of all integers i such that:
//1 <= i <= n
//The decimal representation of i * i can be partitioned into contiguous substrings such that the sum of the integer values of these substrings equals i.




class Solution {
    private:
        // Helper function to check if it's possible to partition the string
        // to get sum equal to target
        bool canPartition(string& s, int start, int target) {
            // Base cases
            if (start >= s.length()) {
                return target == 0;
            }
            if (target < 0) {
                return false;
            }
            
            // Try all possible partitions from current position
            long long currentNum = 0;
            for (int i = start; i < s.length(); i++) {
                currentNum = currentNum * 10 + (s[i] - '0');
                
                // Check for overflow
                if (currentNum > INT_MAX) {
                    break;
                }
                
                // Recursively check if remaining string can be partitioned
                if (canPartition(s, i + 1, target - currentNum)) {
                    return true;
                }
            }
            return false;
        }
        
        // Helper function to check if a number is a punishment number
        bool isPunishmentNumber(int i) {
            // Calculate square
            long long square = (long long)i * i;
            
            // Convert to string
            string squareStr = to_string(square);
            
            // Check if it can be partitioned
            return canPartition(squareStr, 0, i);
        }
        
    public:
        int punishmentNumber(int n) {
            int sum = 0;
            
            // Check each number from 1 to n
            for (int i = 1; i <= n; i++) {
                if (isPunishmentNumber(i)) {
                    sum += i * i;
                }
            }
            
            return sum;
        }
    };