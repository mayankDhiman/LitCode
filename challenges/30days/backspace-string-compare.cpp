class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack <char> s, t;
        for (auto c : S) {
            if (s.empty()) {
                if (c != '#') s.push(c);
                continue;
            }
            if (c == '#')
                s.pop();
            else
                s.push(c);
        }
        for (auto c : T) {
            if (t.empty()) {
                if (c != '#') t.push(c);
                continue;
            }
            if (c == '#')
                t.pop();
            else 
                t.push(c);
        }
        return (s == t);
    }
};
