//You have n  tiles, where each tile has one letter tiles[i] printed on it.
//Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.

class Solution {
    private:
        unordered_map<char, int> freq;
        int result = 0;
        
        void backtrack(int len, string& current, const int totalLen) {
            // Add current sequence if it's non-empty
            if (!current.empty()) {
                result++;
            }
            
            // Try adding each available letter
            for (auto& [letter, count] : freq) {
                if (count > 0) {
                    current.push_back(letter);
                    freq[letter]--;
                    
                    backtrack(len + 1, current, totalLen);
                    
                    // Backtrack
                    current.pop_back();
                    freq[letter]++;
                }
            }
        }
        
    public:
        int numTilePossibilities(string tiles) {
            // Count frequency of each letter
            for (char c : tiles) {
                freq[c]++;
            }
            
            string current = "";
            backtrack(0, current, tiles.length());
            
            return result;
        }
    };
    