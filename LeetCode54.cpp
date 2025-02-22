//Removing Stars From a String

class Solution {
    public:
        string removeStars(string s) {
            // Keep track of the position where we'll place next character
            int writeIndex = 0;
            
            // Iterate through the string
            for (int readIndex = 0; readIndex < s.length(); readIndex++) {
                if (s[readIndex] == '*') {
                    // If we find a star, move writeIndex back by 1 (if possible)
                    if (writeIndex > 0) {
                        writeIndex--;
                    }
                } else {
                    // Place current character at writeIndex position
                    s[writeIndex] = s[readIndex];
                    writeIndex++;
                }
            }
            
            // Return the substring from 0 to writeIndex
            return s.substr(0, writeIndex);
        }
    };