//Regular Expression Matching
//Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).
  
class Solution {
    public:
        bool isMatch(string s, string p) {
            int m = s.length();
            int n = p.length();
            
            // dp[i][j] represents if s[0...i-1] matches p[0...j-1]
            vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
            
            // Empty pattern matches empty string
            dp[0][0] = true;
            
            // Handle patterns like a*, a*b*, etc. matching empty string
            for (int j = 2; j <= n; j++) {
                if (p[j-1] == '*') {
                    dp[0][j] = dp[0][j-2];
                }
            }
            
            // Fill the dp table
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    if (p[j-1] == '*') {
                        
                        dp[i][j] = dp[i][j-2] || 
                                  (dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
                    }
                    else if (p[j-1] == '.' || s[i-1] == p[j-1]) {
                        
                        dp[i][j] = dp[i-1][j-1];
                    }
                }
            }
            
            return dp[m][n];
        }
    };
 