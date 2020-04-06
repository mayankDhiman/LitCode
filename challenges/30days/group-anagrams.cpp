// Group Anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map < vector <int>, vector <string> > gp;
        for (auto s : strs){
            vector <int> cn(26);
            for (auto c : s){
                cn[c - 'a'] += 1;
            }
            gp[cn].push_back(s);
        }
        vector < vector <string> > ret;
        for (auto x : gp){
            ret.push_back(x.second);
        }
        return ret;
    }
};
