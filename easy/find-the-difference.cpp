// 389. Find the Difference

class Solution {
public:
    char findTheDifference(string s, string t) {
        int cn[26]; memset(cn, 0, sizeof cn);
        for (auto c : s)    cn[c - 'a'] += 1;
        char ret;
        for (auto c : t){
            if (cn[c - 'a'] == 0){
                ret = c;
                break;
            }
            cn[c - 'a'] -= 1;
        }
        return ret;
    }
};
