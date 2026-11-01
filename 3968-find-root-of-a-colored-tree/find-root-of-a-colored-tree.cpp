#include <vector>
#include <string>
#include <numeric>

using namespace std;

class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Color mapping: R -> 0, B -> 1, W -> 2
        auto getColorVal = [](char c) {
            if (c == 'R') return 0;
            if (c == 'B') return 1;
            return 2;
        };

        vector<int> col(n);
        for (int i = 0; i < n; ++i) {
            col[i] = getColorVal(colors[i]);
        }

        // Check if parent p to child c is a valid directed edge
        auto isValid = [&](int p, int c) {
            return col[c] == (col[p] + 1) % 3;
        };

        vector<int> parent(n, -1);
        vector<vector<int>> children(n);

        // First DFS to establish tree structure rooted at 0
        auto dfs1 = [&](auto& self, int u, int p) -> void {
            parent[u] = p;
            for (int v : adj[u]) {
                if (v != p) {
                    children[u].push_back(v);
                    self(self, v, u);
                }
            }
        };
        dfs1(dfs1, 0, -1);

        int bad_edges = 0;
        for (int u = 1; u < n; ++u) {
            if (!isValid(parent[u], u)) {
                bad_edges++;
            }
        }

        int result = -1;

        // Second DFS for rerooting and checking conditions
        auto dfs2 = [&](auto& self, int u, int bad) -> void {
            if (bad == 0 && adj[u].size() <= 2) {
                result = u;
                return;
            }
            for (int v : children[u]) {
                // Reroot from u to v: edge changes from u->v to v->u
                bool was_correct = isValid(u, v);
                bool now_correct = isValid(v, u);

                int new_bad = bad;
                if (was_correct) new_bad++;
                if (now_correct) new_bad--;

                self(self, v, new_bad);
                if (result != -1) return;
            }
        };

        dfs2(dfs2, 0, bad_edges);
        return result;
    }
};