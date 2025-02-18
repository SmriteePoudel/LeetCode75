//Roman to Integer

#include <unordered_map>
#include <string>

class Solution {
public:
    int romanToInt(string s) {
        // Create a map to store Roman numeral values
        unordered_map<char, int> values = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int result = 0;
        int prevValue = 0;
        
        // Iterate through the string from right to left
        for (int i = s.length() - 1; i >= 0; i--) {
            int currentValue = values[s[i]];
            
            // If current value is smaller than previous value, subtract it
            // Otherwise add it to the result
            if (currentValue < prevValue) {
                result -= currentValue;
            } else {
                result += currentValue;
            }
            
            prevValue = currentValue;
        }
        
        return result;
    }
};