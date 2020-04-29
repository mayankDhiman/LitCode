// Check if topological ordering exists in a graph (whenever I reach a node, I must have reached all the nodes that lead to that node)
// => check if a cycle exists in a directed graph
// if cycle then no topological ordering

class Solution {
public:
    vector <int> g[int(1e5)];
    int vis[int(1e5)]; // colors, white (unvisited), grey (partially visited / in recursion stack), black (fully visited/explored)
    bool ok = 0;
    
    void dfs(int u, int p){
        cout << u << "\n";
        // for (int i = 0; i < 2; i ++) cout << vis[i] << " "; cout << "\n\n";
        vis[u] = 1; // Marked grey
        for (auto v : g[u]){
            if (vis[v] == 1){
                ok = 1;
                // cycle detected.
                return;
            }
            else if (vis[v] == 0){
                dfs(v, u);
            }
        }
        vis[u] = 2; // Marked black
        return;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        memset(vis, 0, sizeof vis); ok = 0;
        for (auto x : prerequisites){
            g[x[1]].emplace_back(x[0]); // 1 -> 0
        }
        for (int i = 0; i < numCourses; i ++) {
            if (vis[i] == 0){
                dfs(i, -1);
            }
        }
        return !ok;
    }
};
