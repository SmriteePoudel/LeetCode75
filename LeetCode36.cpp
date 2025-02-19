//The k-th Lexicographical String of All Happy Stringd of Length n

class Solution {
    private:
        vector<string> generateHappyStrings(int n) {
            vector<string> result;
            // Start with individual characters
            string current = "";
            generateHappyStringsHelper(n, current, result);
            // Sort the strings lexicographically
            sort(result.begin(), result.end());
            return result;
        }
        
        void generateHappyStringsHelper(int n, string current, vector<string>& result) {
            // Base case: if we've built a string of length n
            if (current.length() == n) {
                result.push_back(current);
                return;
            }
            
            // Try adding each possible character
            for (char c : {'a', 'b', 'c'}) {
                // If current is empty or the last character is different
                if (current.empty() || current.back() != c) {
                    generateHappyStringsHelper(n, current + c, result);
                }
            }
        }
        
    public:
        string getHappyString(int n, int k) {
            // Generate all happy strings of length n
            vector<string> happyStrings = generateHappyStrings(n);
            
            // If k is greater than the number of happy strings, return empty string
            if (k > happyStrings.size()) {
                return "";
            }
            
            // Return the kth string (k is 1-indexed, so we subtract 1)
            return happyStrings[k - 1];
        }
    };