class Solution {
public:
    bool isAnagram(string s, string t) {
        int count1[26], count2[26]; memset(count1, 0, sizeof(count1)); memset(count2, 0, sizeof(count2));
        for (auto c : s)    count1[c - 'a'] += 1;
        for (auto c : t)    count2[c - 'a'] += 1;
  
        for (int i = 0; i < 26; i ++)   cout << count1[i] << " " << count2[i] << "\n";
            
        for (int i = 0; i < 26; i ++){
            if (count1[i] != count2[i]){
                return 0;
            }
        }
        return 1;
    }
};

11 1


100