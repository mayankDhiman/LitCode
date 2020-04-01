class Solution {
public:
    int numJewelsInStones(string J, string S) {
        sort(J.begin(), J.end());
        int countJewels = 0;
        for (int i = 0; i < S.size(); i ++)
        {
            if (binary_search(J.begin(), J.end(), S[i])){
                countJewels += 1;
            }
        }
        return countJewels;
    }
};