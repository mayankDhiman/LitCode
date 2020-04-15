// Last Stone Weight

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        multiset <int, greater <int> > a(stones.begin(), stones.end());
        while (a.size() > 1) {
            int x = *a.begin();  a.erase(a.find(x));
            int y = *a.begin();  a.erase(a.find(y));
            if (abs(x - y)) a.emplace(abs(x - y));
        }
        if (a.size() == 0)  return 0;
        else    return *a.begin();
    } 
};
