// 743. Network Delay Time

class Solution {
public:
    vector < pair <int, int> > a[int(1e5)];
    vector <int> tin;   vector <bool> vis;
    int n;    
    void dij(int s) {
        tin[s] = 0;
        for (int i = 1; i <= n; i++) 
        {
            int v = -1;
            for (int j = 1; j <= n; j++) {
                if (!vis[j] && (v == -1 || tin[j] < tin[v]))
                    v = j;
            }
            if (tin[v] == 2e9)
                break;
            vis[v] = true;
            for (auto edge : a[v]) {
                int to = edge.first;
                int len = edge.second;
                if (tin[v] + len < tin[to]) {
                    tin[to] = tin[v] + len;
                }
            }
        }
    }
    
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        tin.resize(N + 1, 2e9);  vis.resize(N + 1, false); n = N;
        for (int i = 0; i < times.size(); i ++ ) {
            a[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        dij(K);
        int ret = 0;        
        for (int i = 1; i <= N; i ++) {
            if (tin[i] == 2e9) return -1;
            ret = max(ret, tin[i]);
        }
        return ret;
    }
};
