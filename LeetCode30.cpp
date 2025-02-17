//Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

class Solution {
    private:
        bool isVowel(char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        }
        
    public:
        int maxVowels(string s, int k) {
            // Count vowels in first window of size k
            int currentVowels = 0;
            for (int i = 0; i < k && i < s.length(); i++) {
                if (isVowel(s[i])) {
                    currentVowels++;
                }
            }
            
            // Initialize maxVowels with current window count
            int maxVowels = currentVowels;
            
            // Slide the window and update counts
            for (int i = k; i < s.length(); i++) {
                // Remove contribution of character going out of window
                if (isVowel(s[i - k])) {
                    currentVowels--;
                }
                
                // Add contribution of character coming into window
                if (isVowel(s[i])) {
                    currentVowels++;
                }
                
                // Update maximum if current count is greater
                maxVowels = max(maxVowels, currentVowels);
                
               
                if (maxVowels == k) {
                    return k;
                }
            }
            
            return maxVowels;
        }
    };