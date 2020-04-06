// 1376. Time Needed to Inform All Employees

class Solution {
public:
    int n;
    vector <int> aj[int(1e5)];            
    vector <bool> v; 
    vector <int> rc, it;
    
    void dfs(int s, int cr) {
        v[s] = true;
        rc[s] = cr;
        for (auto x : aj[s]) {
            if (!v[x])
                dfs(x, cr + it[s]);
        }
    }
        
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        n = manager.size(); v.resize(n, false); rc.resize(n, -1); it = informTime;
        for (int i = 0; i < manager.size(); i ++){
            if (manager[i] != -1)
                aj[manager[i]].push_back(i);
        }
        dfs(headID, 0);
        return *max_element(rc.begin(), rc.end());
    }

};
