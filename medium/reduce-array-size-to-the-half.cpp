// 1338. Reduce Array Size to The Half

class Solution {
public:
    int minSetSize(vector<int>& a) {
        map <int, int> cn;  
        for (auto &i : a)    cn[i] += 1;
        vector <int> b;
        int t = 0, t_;
        for (auto c : cn){
            b.push_back(c.second);
            t += c.second;
        }   t_ = t;
        sort(b.begin(), b.end(), greater <int> ());
        int ret = 0;
        for (auto &i : b) {
            t -= i;
            ret += 1;
            if (t <= t_/2){
                break;
            }
        }
        return ret;
    }
};

