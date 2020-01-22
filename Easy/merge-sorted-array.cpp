class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        int i = 0, j = 0;
        vector <int> nums;
        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) {
                nums.push_back(nums1[i]);
                i += 1;
            }
            else {
                nums.push_back(nums2[j]);
                j += 1;
            }
        }
        
        
        while (i < n)  {
            nums.push_back(nums1[i]);
            i += 1;
        }
        
        while (j < m) {
            nums.push_back(nums2[j]);
            j += 1;
        }

        nums1 = nums;
    }
};