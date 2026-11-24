#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    void backtrack(int index, int remaining, vector<int>& candidates,
                   vector<int>& current, vector<vector<int>>& ans) {
        if (remaining == 0) {
            ans.push_back(current);
            return;
        }
        if (index == static_cast<int>(candidates.size()) || remaining < 0) {
            return;
        }

        // Option 1: Include candidates[index] again (unlimited reuse)
        current.push_back(candidates[index]);
        backtrack(index, remaining - candidates[index], candidates, current, ans);
        current.pop_back();

        // Option 2: Move to the next candidate
        backtrack(index + 1, remaining, candidates, current, ans);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> current;
        backtrack(0, target, candidates, current, ans);
        return ans;
    }
};