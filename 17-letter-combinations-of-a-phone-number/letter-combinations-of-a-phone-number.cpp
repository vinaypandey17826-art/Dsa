#include <vector>
#include <string>

class Solution {
private:
    void solve(int index, string& digits, string& current, vector<string>& result, const vector<string>& mapping) {
        // Base case: if the current combination length matches the digits string length
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        
        // Get the letters corresponding to the current digit
        int digit = digits[index] - '0';
        string letters = mapping[digit];
        
        // Iterate through all possible letters for this digit
        for (int i = 0; i < letters.length(); i++) {
            current.push_back(letters[i]);          // Do
            solve(index + 1, digits, current, result, mapping); // Recurse
            current.pop_back();                     // Backtrack (undo)
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }
        
        // Mapping from digit to corresponding letters on a telephone keypad
        vector<string> mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };
        
        string current = "";
        solve(0, digits, current, result, mapping);
        return result;
    }
};