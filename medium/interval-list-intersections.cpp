// 986. Interval List Intersections

// The interval with shortest endpoint can intersect only one in the other array.

class Solution {
public:
    
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        vector < vector <int> > ret;
        int n = a.size(), m = b.size();
        int i = 0, j = 0;
        while (i < n && j < m) {
            int p = a[i][0], q = a[i][1], r = b[j][0], s = b[j][1];
            int pp = max(p, r), qq = min(q, s);
            if (pp <= qq) {
                vector <int> r = {pp, qq};
                ret.emplace_back(r);
            }
            if (q < s){
                i += 1;
            }
            else if (s < q){
                j += 1;                
            }
            else{
                i += 1;
                j += 1;
            }                
        }        
        return ret;
    }
};
