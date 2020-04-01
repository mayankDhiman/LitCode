// 884. Uncommon Words from Two Sentences


class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        vector <string> a;  map <string, int> aa, bb;
        string temp;    A += " ";
        for (int i = 0; i < A.size(); i ++){
            if (A[i] == ' '){
                a.push_back(temp);
                aa[temp] += 1;
                temp = "";
            }
            else{
                temp += A[i];
            }
        }
        vector <string> b;
        temp = "";    B += " ";
        for (int i = 0; i < B.size(); i ++){
            if (B[i] == ' '){
                b.push_back(temp);
                bb[temp] += 1;
                temp = "";
            }
            else{
                temp += B[i];
            }
        }
        
        
        set <string> ret;
        for (auto word : aa){
            if (word.second == 1){
                if (bb.find(word.first) == bb.end()){
                    ret.insert(word.first);
                }
            }
        }
        for (auto word : bb){
            if (word.second == 1){
                if (aa.find(word.first) == aa.end()){
                    ret.insert(word.first);
                }
            }
        }
        
        
        vector <string> rt(ret.begin(), ret.end());
        return rt;
    }
};