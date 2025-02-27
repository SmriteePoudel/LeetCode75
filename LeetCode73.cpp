//Valid Parentheses
class Solution {
    public:
        bool isValid(string s) {
            stack<char> brackets;
            
            for (char c : s) {
                // If it's an opening bracket, push onto stack
                if (c == '(' || c == '{' || c == '[') {
                    brackets.push(c);
                } 
                // If it's a closing bracket
                else {
                    // If stack is empty, no matching open bracket exists
                    if (brackets.empty()) {
                        return false;
                    }
                    
                    // Check if the current closing bracket matches the top of the stack
                    char top = brackets.top();
                    if ((c == ')' && top == '(') || 
                        (c == '}' && top == '{') || 
                        (c == ']' && top == '[')) {
                        brackets.pop();
                    } else {
                        // If not matching, invalid sequence
                        return false;
                    }
                }
            }
            
            // If stack is empty, all brackets were properly matched and closed
            return brackets.empty();
        }
    };