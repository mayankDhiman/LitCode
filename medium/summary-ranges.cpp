// 228. Summary Ranges

class Solution {
public:
    vector<string> summaryRanges(vector<int>& a) {
        long long n = a.size(), i = 0, j = 0;
        vector < pair <long long, long long> > re;
        while (i < n && j < n) {
            j = i + 1;
            while ((j < n) && (a[j] == 1 + a[j - 1])){
                cout << j << "\n";
                j += 1;
            }
            re.push_back({a[i], a[j - 1]});
            i = j;
        }
        vector <string> ret;
        for (auto s : re){
            string r;
            if (s.first != s.second){
                r += to_string(s.first) + "->" + to_string(s.second);
            }
            else{
                r += to_string(s.first);
            }
            ret.push_back(r);
        }   
        return ret;
    }
};
