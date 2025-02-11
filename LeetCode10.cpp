// Longest Palindromic Substring
//Given a string s, return the longest palindromic substring in s.

  class Solution {
    private:
        // Helper function to expand around center and find palindrome length
        pair<int, int> expandAroundCenter(string& s, int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
            // Return the valid palindrome boundaries
            return {left + 1, right - 1};
        }
    
    public:
        string longestPalindrome(string s) {
            if (s.length() < 2) return s;
            
            int start = 0, maxLength = 1;
            
            // Iterate through each character as potential center
            for (int i = 0; i < s.length(); i++) {
                // Check for odd length palindromes (single char center)
                auto [left1, right1] = expandAroundCenter(s, i, i);
                int len1 = right1 - left1 + 1;
                
                // Check for even length palindromes (two char center)
                auto [left2, right2] = expandAroundCenter(s, i, i + 1);
                int len2 = right2 - left2 + 1;
                
                // Update if we found a longer palindrome
                if (len1 > maxLength) {
                    start = left1;
                    maxLength = len1;
                }
                if (len2 > maxLength) {
                    start = left2;
                    maxLength = len2;
                }
            }
            
            return s.substr(start, maxLength);
        }
    };