// 930. Binary Subarrays With Sum

class Solution {
public:
    int numSubarraysWithSum(vector<int>& a, int s) {
        int n = a.size(), cr = 0;   int cn[int(1e5)];   memset(cn, 0, sizeof cn);
        cn[0] += 1;
        for (int i = 0; i < n; i ++) {
            cr += a[i];
            cn[cr] += 1;
        }
        int ret = 0;
        for (int i = s; i < int(1e5); i ++) {
            if (s == 0){
                ret += cn[i] * (cn[i] - 1) / 2;
            }
            else{
                int j = i - s;
                ret += cn[i] * cn[j];                
            }
        }
        return ret;
    }
};

// 0 1 1 2 2 3
