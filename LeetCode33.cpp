//Construct Smallest Number from DI String

class Solution {
    public:
        string smallestNumber(string pattern) {
            int n = pattern.length();
            string result(n + 1, '0');
            vector<bool> used(10, false);
            
            // Find next available smallest number - returns char instead of int
            auto getNextSmallest = [&used]() -> char {
                for (int i = 1; i <= 9; i++) {
                    if (!used[i]) {
                        used[i] = true;
                        return i + '0';
                    }
                }
                return '0';
            };
            
            // Fill decreasing sequences from the start of each sequence
            for (int i = 0; i <= n; i++) {
                // Skip if already filled
                if (result[i] != '0') continue;
                
                // Find length of decreasing sequence
                int dCount = 0;
                int j = i;
                while (j < n && pattern[j] == 'D') {
                    dCount++;
                    j++;
                }
                
                // Fill increasing number if no decreasing sequence
                if (dCount == 0) {
                    result[i] = getNextSmallest();
                    continue;
                }
                
                // Fill decreasing sequence
                for (int k = 0; k <= dCount; k++) {
                    result[i + dCount - k] = getNextSmallest();
                }
                
                // Skip the processed decreasing sequence
                i += dCount;
            }
            
            return result;
        }
    };