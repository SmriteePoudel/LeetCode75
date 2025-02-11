//Reverse Vowels of a String
//Given a string s, reverse only all the vowels in the string and return it.
//The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

class Solution {
    public:
        bool isVowel(char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                   c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
        }
        
        string reverseVowels(string s) {
            // Initialize two pointers
            int left = 0;
            int right = s.length() - 1;
            
            // Move pointers towards each other
            while (left < right) {
                // Find next vowel from left
                while (left < right && !isVowel(s[left])) {
                    left++;
                }
                
                // Find next vowel from right
                while (left < right && !isVowel(s[right])) {
                    right--;
                }
                
                // Swap vowels
                if (left < right) {
                    swap(s[left], s[right]);
                    left++;
                    right--;
                }
            }
            
            return s;
        }
    };