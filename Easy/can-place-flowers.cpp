class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for (int i = 0; i < flowerbed.size(); i ++){
            bool ok;
            if (!flowerbed[i]){
                ok = 1;
                if (i > 0){
                    ok &= !(flowerbed[i - 1]); 
                }
                if (i < flowerbed.size() - 1){
                    ok &= !(flowerbed[i + 1]);
                }
                if (ok){
                    count += 1;
                    flowerbed[i] = 1;
                }
            }
            else{
                ok = 0;
            }
            cout << i << " " << ok << "\n"; 
        }
        
        return (count >= n);
    }
};