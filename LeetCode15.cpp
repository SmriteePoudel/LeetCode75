
//Reverse Words in a String

//Given an input string s, reverse the order of the words.
//A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
//Return a string of the words in reverse order concatenated by a single space.

class Solution {
    public:
        string reverseWords(string s) {
            // Result string to store words
            string result;
            int i = 0;
            int n = s.length();
            
            while(i < n) {
                // Skip multiple spaces
                while(i < n && s[i] == ' ') i++;
                
                if(i >= n) break;
                
                // Find the end of current word
                int j = i;
                while(j < n && s[j] != ' ') j++;
                
                // If this is not the first word, add a space before it
                if(!result.empty()) {
                    result = s.substr(i, j-i) + " " + result;
                } else {
                    result = s.substr(i, j-i);
                }
                
                i = j + 1;
            }
            
            return result;
        }
    };