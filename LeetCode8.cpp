//Clear Digits
//Your task is to remove all digits by doing this operation repeatedly:
//Delete the first digit and the closest non-digit character to its left.
//Return the resulting string after removing all digits.


class Solution {
    public:
        string clearDigits(string s) {
            while (true) {
                // Find first digit
                int digitPos = -1;
                for (int i = 0; i < s.length(); i++) {
                    if (isdigit(s[i])) {
                        digitPos = i;
                        break;
                    }
                }
                
                // If no digit found, break
                if (digitPos == -1) break;
                
                // Find closest non-digit to left
                int leftPos = -1;
                for (int i = digitPos - 1; i >= 0; i--) {
                    if (!isdigit(s[i])) {
                        leftPos = i;
                        break;
                    }
                }
                
                // Remove both characters
                if (leftPos != -1) {
                    s.erase(digitPos, 1);  // Remove digit first
                    s.erase(leftPos, 1);   // Then remove left character
                } else {
                    // If no character to left, just remove digit
                    s.erase(digitPos, 1);
                }
            }
            
            return s;
        }
    };