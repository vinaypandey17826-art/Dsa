#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        // Vector to store the last seen index of each ASCII character, initialized to -1
        std::vector<int> lastSeen(128, -1);
        
        int maxLength = 0;
        int left = 0; // Left boundary of the sliding window
        
        for (int right = 0; right < s.length(); ++right) {
            char currentChar = s[right];
            
            // If the character is repeated inside the current window,
            // shrink the window by moving 'left' past its last occurrence
            if (lastSeen[currentChar] >= left) {
                left = lastSeen[currentChar] + 1;
            }
            
            // Record/update the current character's index
            lastSeen[currentChar] = right;
            
            // Calculate the current window size and update the maximum length found
            maxLength = std::max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};