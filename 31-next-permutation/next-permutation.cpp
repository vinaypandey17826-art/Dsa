#include <vector>
#include <algorithm>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int n = nums.size();
        int idx = -1;

        // Step 1: Find the first decreasing element from the right (the breakpoint)
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }

        // If no breakpoint exists, the array is in descending order (e.g., [3, 2, 1])
        // The next permutation is the reverse (ascending order, e.g., [1, 2, 3])
        if (idx == -1) {
            std::reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Find the smallest element to the right of 'idx' that is larger than nums[idx]
        for (int i = n - 1; i > idx; --i) {
            if (nums[i] > nums[idx]) {
                std::swap(nums[i], nums[idx]);
                break;
            }
        }

        // Step 3: Reverse the elements to the right of 'idx' to get the smallest lexicographical order
        std::reverse(nums.begin() + idx + 1, nums.end());
    }
};