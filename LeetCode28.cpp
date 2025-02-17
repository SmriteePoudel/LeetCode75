//Integer to Roman


#include <string>
#include <vector>

class Solution {
private:
    // Pair of value and corresponding Roman numeral symbol(s)
    const std::vector<std::pair<int, std::string>> romanValues = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}
    };

public:
    std::string intToRoman(int num) {
        std::string result = "";
        
        // Iterate through each value-symbol pair
        for (const auto& pair : romanValues) {
            // While the number is greater than or equal to current value
            while (num >= pair.first) {
                result += pair.second;
                num -= pair.first;
            }
        }
        
        return result;
    }
};