//Merge Strings Alternately
//You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.
//Return the merged string.

class Solution {
    public:
        string mergeAlternately(string word1, string word2) {
            string merged;
            int i = 0, j = 0;
            while (i < word1.size() && j < word2.size()) {
                merged += word1[i++];
                merged += word2[j++];
            }
            // Append remaining characters from word1 or word2
            merged += word1.substr(i);
            merged += word2.substr(j);
            return merged;
        }
    };
    