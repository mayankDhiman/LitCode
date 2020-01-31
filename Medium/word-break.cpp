class Solution {
public:
    // Top Down Implementation
    string t;   set <string> a;
    vector < vector <int> > cache;
    
    bool dp(int i, int j)
    {
        if (i == t.size()){
            return 1;
        }
        if (j == t.size()){
            string cut = t.substr(i, j - i + 1);
            if (find(a.begin(), a.end(), cut) == a.end()){
                return 0;
            }            
            else{
                return 1;
            }
        }
        
        if (cache[i][j] != -1)  return cache[i][j];
            
        bool ok1 = 0, ok2 = 0;
        string curr = t.substr(i, curr.size() - i);
        ok1 = dp(i, j + 1);                
        string cut = t.substr(i, j - i + 1);
        if (find(a.begin(), a.end(), cut) == a.end()){
            ok2 = 0;
        }
        else{
            ok2 = dp(j + 1, j + 1);            
        }
        
        
        return cache[i][j] = (ok1 or ok2);
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        t = s;  set <string> _a(wordDict.begin(), wordDict.end()); a = _a;  vector <vector <int> > _c(1000, vector <int> (1000, -1)); cache = _c;
        return dp(0, 0);
    }

    // TODO: Bottom Up implementation
};