//Decode String


#include <string>
#include <stack>

class Solution {
public:
    string decodeString(string s) {
        stack<string> stringStack;  // Stack to store partial strings
        stack<int> countStack;      // Stack to store counts
        string currentString;
        int currentCount = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                currentCount = currentCount * 10 + (c - '0');
            }
            else if (c == '[') {
                // Push current state to stacks and reset current variables
                countStack.push(currentCount);
                stringStack.push(currentString);
                currentCount = 0;
                currentString = "";
            }
            else if (c == ']') {
                // Get the number of repetitions
                int repeatTimes = countStack.top();
                countStack.pop();
                
                // Get the previous string
                string previousString = stringStack.top();
                stringStack.pop();
                
                // Repeat current string and append to previous string
                string repeatedString = "";
                for (int i = 0; i < repeatTimes; i++) {
                    repeatedString += currentString;
                }
                currentString = previousString + repeatedString;
            }
            else {
                // Regular character, append to current string
                currentString += c;
            }
        }
        
        return currentString;
    }
};