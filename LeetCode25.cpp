//String Compression
//iven an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

//If the group's length is 1, append the character to s.
//Otherwise, append the character followed by the group's length.


class Solution {
    public:
        int compress(vector<char>& chars) {
            int writePos = 0;  // Position to write the compressed characters
            int start = 0;     // Start of current group
            
            for (int read = 0; read <= chars.size(); read++) {
                // When we reach the end or find a different character
                if (read == chars.size() || chars[read] != chars[start]) {
                    // Write the character
                    chars[writePos++] = chars[start];
                    
                    // If group length > 1, write the count
                    if (read - start > 1) {
                        string count = to_string(read - start);
                        for (char c : count) {
                            chars[writePos++] = c;
                        }
                    }
                    
                    // Update start of next group
                    start = read;
                }
            }
            
            return writePos;
        }
    };