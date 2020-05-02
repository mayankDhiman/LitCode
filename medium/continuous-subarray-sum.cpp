class Solution {
public:
    // 1. Prefix sum containing %k values
    // 2. problem: find if difference of any two elements is equal to zero or not.
    // 3. use map, if any occurs twice "YES" else "NO" (refresh map for each index, removing the decrementing a[i - 1], accounting for "atleast 2")
    bool checkSubarraySum(vector<int>& nums, int k) {
        long long n = nums.size(); vector <long long> a(n + 1); 
        unordered_map <long long, long long> cn; cn[0] += 1; bool ok = 0; 
        for (int i = 1; i < n + 1; i ++){
            if (k != 0)
                a[i] = (( (a[i - 1]%k + k)%k + (nums[i - 1]%k + k)%k )%k + k)%k;            
            else
                a[i] = a[i - 1] + nums[i - 1];
            if (i >= 2){
                cn[a[i - 1]] -= 1;
                if (cn[a[i]] > 0) { ok = 1; break; }                
                cn[a[i - 1]] += 1;
            }
            cn[a[i]] += 1;
        }
        return ok;
    }
};
