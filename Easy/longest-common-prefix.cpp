class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string longestPrefix;
        
        int len = INT_MAX;
        for (int i = 0; i < strs.size(); i ++){
            len = min(len, int(strs[i].size()));
        }
        if (len == INT_MAX) len = 0;

        for (int i = 0; i < len; i ++)
        {
            char c = strs[0][i];
            bool insert = 1;
            for (int j = 0; j < strs.size(); j ++){
                if (strs[j][i] != c){
                    insert = 0;
                }
            } 
            if (insert){
                longestPrefix += string(1, c);
            }                
            else   
                break;
        }
        
        return longestPrefix;
    }
};