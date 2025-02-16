//String to Integer(atoi)

class Solution {
    public:
        int myAtoi(string s) {
            int i = 0;
            int n = s.length();
            
            // Skip whitespace
            while (i < n && s[i] == ' ') {
                i++;
            }
            
            // Handle empty string or only whitespace
            if (i == n) return 0;
            
            // Handle sign
            bool isNegative = false;
            if (s[i] == '-' || s[i] == '+') {
                isNegative = (s[i] == '-');
                i++;
            }
            
            // Convert digits
            long result = 0;
            while (i < n && isdigit(s[i])) {
                result = result * 10 + (s[i] - '0');
                
                // Check overflow/underflow
                if (isNegative && -result < INT_MIN) return INT_MIN;
                if (!isNegative && result > INT_MAX) return INT_MAX;
                
                i++;
            }
            
            return isNegative ? -result : result;
        }
    };