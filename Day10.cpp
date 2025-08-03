//minimum score after removl on a tree
class Solution {
public:
    
            
    int timer = 0;
    vector<int> in, out, subXor;
    vector<vector<int>> tree;

    void dfs(int u, int parent, const vector<int>& nums) {
        in[u] = timer++;
        subXor[u] = nums[u];
        for (int v : tree[u]) {
            if (v != parent) {
                dfs(v, u, nums);
                subXor[u] ^= subXor[v];
            }
        }
        out[u] = timer++;
    }

    bool isAncestor(int u, int v) {
        return in[u] <= in[v] && out[v] <= out[u];
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        tree.assign(n, {});
        for (auto& e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        in.resize(n);
        out.resize(n);
        subXor.resize(n);
        dfs(0, -1, nums);
        int totalXor = subXor[0];
        int res = INT_MAX;

        // Try all pairs of edges (represented by their child nodes)
        for (auto& e1 : edges) {
            int a = isAncestor(e1[0], e1[1]) ? e1[1] : e1[0];
            for (auto& e2 : edges) {
                if (e1 == e2) continue;
                int b = isAncestor(e2[0], e2[1]) ? e2[1] : e2[0];
                int x, y, z;
                if (isAncestor(a, b)) {
                    x = subXor[b];
                    y = subXor[a] ^ subXor[b];
                    z = totalXor ^ subXor[a];
                } else if (isAncestor(b, a)) {
                    x = subXor[a];
                    y = subXor[b] ^ subXor[a];
                    z = totalXor ^ subXor[b];
                } else {
                    x = subXor[a];
                    y = subXor[b];
                    z = totalXor ^ subXor[a] ^ subXor[b];
                }
                int mx = max({x, y, z});
                int mn = min({x, y, z});
                res = min(res, mx - mn);
            }
        }
        return res;
        
    }
};