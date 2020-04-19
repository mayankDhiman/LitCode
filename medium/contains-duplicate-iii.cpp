// 220. Contains Duplicate III (FIXME)

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset <long long> ks;
        bool ok = 0;    long long n = nums.size();
        for (int i = 0; i < n; i ++) {
            if (i > k)  ks.erase(nums[i - k - 1]);
            auto it = lower_bound(ks.begin(), ks.end(), 1ll*nums[i] - 1ll*t);
            if (it != ks.end()){
                if (*it <= nums[i]*1ll + t*1ll) ok = 1;
            }
            // for (auto c : ks)   cout << c << " ";   cout << "\n"; cout << ok << "\n\n";
            ks.insert(nums[i]);
        }
        return ok;
    }
};
