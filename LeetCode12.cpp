//Max Sum of a pair with equal sum of digits
//You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].
//Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    // Helper function to calculate sum of digits
    int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    
public:
    int maximumSum(vector<int>& nums) {
        // Map to store the maximum number for each digit sum
        unordered_map<int, int> maxNumForDigitSum;
        int maxSum = -1;
        
        for (int num : nums) {
            int digitSum = getDigitSum(num);
            
            // If we've seen this digit sum before
            if (maxNumForDigitSum.count(digitSum)) {
                // Update maxSum if current pair gives larger sum
                maxSum = max(maxSum, num + maxNumForDigitSum[digitSum]);
                // Update the maximum number for this digit sum
                maxNumForDigitSum[digitSum] = max(maxNumForDigitSum[digitSum], num);
            } else {
                // First time seeing this digit sum
                maxNumForDigitSum[digitSum] = num;
            }
        }
        
        return maxSum;
    }
};