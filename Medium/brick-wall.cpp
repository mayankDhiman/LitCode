// 554. Brick Wall


class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map <int, int> cn;
        for (auto row : wall){
            int curr = 0;
            for (int i = 0; i < row.size() - 1; i ++){
                curr += row[i];
                cn[curr] += 1;
            }
        }        
                
        int ret = wall.size();
        for (auto c : cn){
            ret = min(ret, int(wall.size() - c.second));
        }
        return ret;
    }
};