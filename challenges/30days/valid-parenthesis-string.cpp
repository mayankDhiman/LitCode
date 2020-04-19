// Valid Parenthesis String (Backtracking)

class Solution {
public:
    map < pair <int, stack <char> >, bool> ch;
    string a;
    int n;
    stack <char> foo(stack <char> st, char x) {
        if ((st.empty()) || (x == '(')) {
            st.push(x); return st;
        }
        char y = st.top();
        if (x == ')' && y == '('){
            st.pop();
            return st;
        }
        return st;
    }
    
    bool dp(int i, stack <char> st) {
        if (i == n) {
            return (st.empty());
        }
        if (ch.find({i, st}) != ch.end())  return ch[{i, st}];
        bool r1 = 0, r2 = 0, r3 = 0, r4 = 0;
        if (a[i] == '(' or a[i] == ')'){
            stack <char> nx = foo(st, a[i]);
            r1 = dp(i + 1, nx);
        }
        else {
            stack <char> nx1 = foo(st, '('), nx2 = foo(st, ')'), nx3 = st;
            r2 = dp(i + 1, nx1);           
            r3 = dp(i + 1, nx2);
            r4 = dp(i + 1, nx3);
        }
        return ch[{i, st}] = (r1 or r2 or r3 or r4);
    }
    
    bool checkValidString(string s) {
        ch.clear();
        a = s;  stack <char> st; n = a.size();
        return dp(0, st);      
    }
};
