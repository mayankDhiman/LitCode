class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i <= int(haystack.size() - needle.size()); i ++)
        {
            int location = i, j = 0, k = i;
            while(needle[j] == haystack[k] && j < needle.size() && k < haystack.size()){
                j += 1; k += 1;
            }
            if (j == needle.size()) return location;
        }
        
        return -1;
    }
};