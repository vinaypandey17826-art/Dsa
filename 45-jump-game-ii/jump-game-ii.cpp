class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int jumps = 0;
        int currentEnd = 0; // End of the range covered by `jumps` jumps
        int farthest = 0;   // Farthest index reachable from indices seen so far

        // Stop at n - 2: once currentEnd reaches or passes n - 1, we're done
        for (int i = 0; i < n - 1; ++i) {
            farthest = max(farthest, i + nums[i]);

            // Finished scanning the current jump's window -> commit to a jump
            if (i == currentEnd) {
                ++jumps;
                currentEnd = farthest;

                if (currentEnd >= n - 1) break;
            }
        }

        return jumps;
    }
};