class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)  return 0;
        string string_x = to_string(x);
        for (int i = 0; i < string_x.size(); i ++){
            if (string_x[i] != string_x[string_x.size() - 1 - i])   return 0;
        }
        return 1;
    }
};