// For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).

//Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.//

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
     if (str1 + str2 != str2 + str1) {
            return "";
        }  
          // Compute the greatest common divisor (GCD) of the lengths of both strings
        int gcdLength = gcd(str1.size(), str2.size());
        
        // The GCD string is the prefix of str1 with length gcdLength
        return str1.substr(0, gcdLength);
    
    
    }
    private:
    // Function to compute the greatest common divisor of two numbers
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
            return a;
    }        
};