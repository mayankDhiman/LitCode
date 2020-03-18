class Solution {
public:
    bool isSubsequence(string s, string t) {
        swap(s, t);
        set <int> pos[26];  for (int i = 0; i < s.size(); i ++) pos[s[i] - 'a'].emplace(i);
        int pr = -1;    bool ok = 1;
        for (int i = 0; i < t.size(); i ++){
            if (pos[t[i] - 'a'].upper_bound(pr) != pos[t[i] - 'a'].end()){
                pr = *(pos[t[i] - 'a'].upper_bound(pr));
            }
            else{
                ok = 0;
            }
            cout << i << " " << ok << "\n";
        }
        
        return ok;
    }
};