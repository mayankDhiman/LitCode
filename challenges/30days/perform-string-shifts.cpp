// Perform String Shifts

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int ns = 0, n = s.size();
        if (n == 1) return s;
        for (auto& x : shift) {
            if (x[0] == 0) ns -= x[1];
            else    ns += x[1];
        }
        ns = (ns%n + n)%n;
        string ret(s.begin(), s.end());
        for (int i = 0; i < n; i ++) {
            if (ns > 0)
                ret[((i + ns)%n + n)%n] = s[i];
            else
                ret[((i - ns)%n + n)%n] = s[i];            
        }
        return ret;
    }
};
