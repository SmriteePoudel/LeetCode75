// Reverse Words in a String
//Given an input string s, reverse the order of the words.
//A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
//Return a string of the words in reverse order concatenated by a single space.

class Solution {
    private:
        // Helper function to reverse characters in a range
        void reverse(string& s, int start, int end) {
            while (start < end) {
                swap(s[start++], s[end--]);
            }
        }
        
        // Helper function to remove extra spaces
        string cleanSpaces(string& s) {
            int i = 0, j = 0;
            int n = s.length();
            
            // Skip leading spaces
            while (j < n && s[j] == ' ') j++;
            
            // Process rest of the string
            bool space = false;
            while (j < n) {
                if (s[j] != ' ') {
                    // Add character
                    s[i++] = s[j++];
                    space = false;
                } else if (!space) {
                    // Add single space
                    s[i++] = ' ';
                    space = true;
                    j++;
                } else {
                    // Skip extra spaces
                    j++;
                }
            }
            
            // Remove trailing space if exists
            if (i > 0 && s[i-1] == ' ') i--;
            
            return s.substr(0, i);
        }
    
    public:
        string reverseWords(string s) {
            // Step 1: Clean up spaces
            s = cleanSpaces(s);
            
            // Step 2: Reverse the entire string
            reverse(s, 0, s.length() - 1);
            
            // Step 3: Reverse each word
            int start = 0;
            for (int end = 0; end <= s.length(); end++) {
                if (end == s.length() || s[end] == ' ') {
                    reverse(s, start, end - 1);
                    start = end + 1;
                }
            }
            
            return s;
        }
    };