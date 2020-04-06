// 387. First Unique Character in a String

class Solution {
public:
    int firstUniqChar(string s) {
        int cn[26]; memset(cn, 0, sizeof cn);
        for (auto c : s){
            cn[c - 'a'] += 1;
        }
        
        for (int i = 0; i < s.size(); i ++) {
            if (cn[s[i] - 'a'] == 1){
                return i;
            } 
        }
        return -1;
    }
};
