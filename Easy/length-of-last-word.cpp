class Solution {
public:
    int lengthOfLastWord(string s) {
        int result = 0, i = s.size() - 1;   while(s[i] == ' ' && i >= 0)  i -= 1;
        while(s[i] != ' ' && i >= 0)  {
            result += 1;
            i -= 1;
        }
        return result;
    }
};