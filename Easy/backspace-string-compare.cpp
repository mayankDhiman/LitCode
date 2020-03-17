class Solution {
public:
    string solve(string A){
        string s;
        for (auto c : A){
            if (c == '#'){
                if (s.size() > 0){
                    s.erase(s.begin() + s.size() - 1);
                }
            }
            else{
                s += c;
            }
        }
        return s;
    }
    
    bool backspaceCompare(string S, string T) {
        return (solve(S) == solve(T));        
    }
};