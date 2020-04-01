class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());   sort(s.begin(), s.end());
        int i = 0, j = 0, ret = 0;
        while ((i < g.size()) && (j < s.size()) ){
            while ( (j < s.size()) && (s[j]<g[i]) )  
                j += 1;   
            if ((j < s.size()) && (i < g.size()))
                ret += (s[j] >= g[i]);
            j += 1;
            i += 1;
        }
        return ret;
    }
};