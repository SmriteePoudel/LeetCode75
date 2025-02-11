//Remove All Occurrences of a Substring
//Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:
//Find the leftmost occurrence of the substring part and remove it from s.
//Return s after removing all occurrences of part.
//A substring is a contiguous sequence of characters in a string.



#include <string>

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (true) {
            // Find the first occurrence of part in s
            size_t pos = s.find(part);
            
            // If part is not found, break the loop
            if (pos == string::npos) {
                break;
            }
            
            // Remove part from s starting at pos
            s.erase(pos, part.length());
        }
        
        return s;
    }
};