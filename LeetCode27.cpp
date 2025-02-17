//Palindrome Number

class Solution {
    public:
        bool isPalindrome(int x) {
            // Negative numbers are not palindromes
            if (x < 0) {
                return false;
            }
            
            // Convert integer to string
            string num = to_string(x);
            
            // Use two pointers: one from start, one from end
            int left = 0;
            int right = num.length() - 1;
            
            // Compare characters until pointers meet
            while (left < right) {
                if (num[left] != num[right]) {
                    return false;
                }
                left++;
                right--;
            }
            
            return true;
        }
    };