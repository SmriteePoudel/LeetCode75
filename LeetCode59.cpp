// Divide Two Integers
//Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
//The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.
//Return the quotient after dividing dividend by divisor.

class Solution {
    public:
        int divide(int dividend, int divisor) {
            // Handle overflow cases
            if (dividend == INT_MIN && divisor == -1) 
                return INT_MAX;
            if (dividend == INT_MIN && divisor == 1)
                return INT_MIN;
                
            // Convert to long to handle INT_MIN case
            long dvd = abs((long)dividend);
            long dvs = abs((long)divisor);
            int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
            long quotient = 0;
            
            // Use bit manipulation for division
            while (dvd >= dvs) {
                long temp = dvs;
                long multiple = 1;
                
                // Find the largest multiple of divisor that's <= dividend
                while (dvd >= (temp << 1)) {
                    temp <<= 1;
                    multiple <<= 1;
                }
                
                dvd -= temp;
                quotient += multiple;
            }
            
            // Apply sign and handle overflow
            quotient *= sign;
            if (quotient > INT_MAX) return INT_MAX;
            if (quotient < INT_MIN) return INT_MIN;
            
            return (int)quotient;
        }
    };