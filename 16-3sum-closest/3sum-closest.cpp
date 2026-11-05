#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        // Sort the array to use the two-pointer technique
        std::sort(nums.begin(), nums.end());
        
        int closestSum = nums[0] + nums[1] + nums[2];
        int n = nums.size();
        
        for (int i = 0; i < n - 2; ++i) {
            // Skip duplicate elements for the first number to avoid redundant work
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                
                // If the exact target is found, return immediately
                if (currentSum == target) {
                    return target;
                }
                
                // Update closestSum if the current sum is closer to the target
                if (std::abs(currentSum - target) < std::abs(closestSum - target)) {
                    closestSum = currentSum;
                }
                
                // Adjust pointers based on comparison with target
                if (currentSum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return closestSum;
    }
};