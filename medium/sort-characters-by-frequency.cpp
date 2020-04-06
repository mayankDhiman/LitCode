class Solution {
public:
    string frequencySort(string s) {
        map <char, int> cn; 
        for (auto c : s)    cn[c] += 1;
        multimap <int, char, greater <int> > icn;
        for (auto ex : cn){
            icn.insert({ex.second, ex.first});
        }
        
        string ret;
        for (auto x : icn){
            int rep = x.first;
            while (rep --) {
                ret += x.second;
            }
        }
        
        return ret;
    }
};
