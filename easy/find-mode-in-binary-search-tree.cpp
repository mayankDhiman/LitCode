// 501. Find Mode in Binary Search Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map <int, int> cn;
    
    void doo(TreeNode* root) {
        if (!root)  return;
        cn[root -> val] += 1;
        doo(root -> left);
        doo(root -> right);
    }
    
    vector<int> findMode(TreeNode* root) {
        cn.clear();
        doo(root);
        int mf = 0;
        for (auto x : cn){
            if (x.second > mf){
                mf = x.second;
            }
        }
        vector <int> res;
        for (auto x : cn){
            if (x.second == mf){
                res.emplace_back(x.first);
            }
        }
        return res;
    }
};
