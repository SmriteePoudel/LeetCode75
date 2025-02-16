//Construct Lexicographically Largest Valid Sequence
//Given an integer n, find a sequence that satisfies all of the following:
//The integer 1 occurs once in the sequence.
//Each integer between 2 and n occurs twice in the sequence.
//For every integer i between 2 and n, the distance between the two occurrences of i is exactly i.
//The distance between two numbers on the sequence, a[i] and a[j], is the absolute difference of their indices, |j - i|.



#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
private:
    bool canPlaceNumber(int num, int pos, vector<int>& sequence, int n) {
        // Check if this number has been used twice already
        int count = 0;
        int firstPos = -1;
        for (int i = 0; i < pos; i++) {
            if (sequence[i] == num) {
                count++;
                if (count == 1) firstPos = i;
            }
        }
        
        // If it's number 1, it can only appear once
        if (num == 1) return count == 0;
        
        // For other numbers, they must appear exactly twice with distance 'num'
        if (count == 0) return true;
        if (count == 1) return (pos - firstPos) == num;
        return false;
    }
    
    bool backtrack(int pos, vector<int>& sequence, int n) {
        if (pos == sequence.size()) {
            // Check if all numbers appear correct number of times
            vector<int> count(n + 1, 0);
            for (int num : sequence) {
                count[num]++;
            }
            if (count[1] != 1) return false;
            for (int i = 2; i <= n; i++) {
                if (count[i] != 2) return false;
            }
            return true;
        }
        
        // Try placing numbers from highest to lowest for lexicographically largest sequence
        for (int num = n; num >= 1; num--) {
            if (canPlaceNumber(num, pos, sequence, n)) {
                sequence[pos] = num;
                if (backtrack(pos + 1, sequence, n)) {
                    return true;
                }
            }
        }
        return false;
    }
    
public:
    vector<int> constructDistancedSequence(int n) {  // Changed function name here
        // Calculate sequence length: 1 appears once, others twice
        int len = 1 + 2 * (n - 1);
        vector<int> sequence(len, 0);
        
        backtrack(0, sequence, n);
        return sequence;
    }
};