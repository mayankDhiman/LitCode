// 210. Course Schedule II

class Solution {
public:

    vector <int> g[int(1e5 + 1)];
    vector <int> vis, result;
    bool ok;
    
    void dfs(int u, int p) {
        vis[u] = 1;
        for (auto v : g[u]){
            if (vis[v] == 1){
                ok = 0; return;
            }
            else if (vis[v] == 0){
                dfs(v, u);
            }
        }
        result.emplace_back(u);
        vis[u] = 2;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vis.resize(int(1e5 + 1), 0);    ok = 1;     result.clear();
        for (auto x : prerequisites){
            g[x[1]].push_back(x[0]);
        }
        
        for (int i = 0; i < numCourses; i ++) {
            if (vis[i] == 0)
                dfs(i, -1);
        }
        if (!ok){
            vector <int> res; return res;
        }
        else{
            reverse(result.begin(), result.end());
            return result;
        }
        
    };
    
};
