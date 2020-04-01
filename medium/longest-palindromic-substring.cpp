// TODO: Manacher'a Algo
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1)    return s;
        
        vector < vector <int> > cache(s.size(), vector <int> (s.size(), -1));
        for (int i = 0; i < s.size(); i ++){
            cache[i][i] = 1;
            if (i == s.size() - 1)  break;
            cache[i][i + 1] = (s[i] == s[i + 1]);
        }
        for (int k = 2; k < s.size(); k ++){
            for (int i = 0, j = k; i < s.size() && j < s.size(); i ++, j ++){
                cache[i][j] = (s[i] == s[j]) && (cache[i + 1][j - 1] == 1);                
             }
        }
        int len = INT_MIN, be;
        for (int i = 0; i < s.size(); i ++){
            for (int j = 0; j < s.size(); j ++){
                if (cache[i][j] == 1 && (j - i + 1 > len)){
                   len = j - i + 1;
                   be = i;
                }
            }
        }
        return s.substr(be, len);   
    }
};
