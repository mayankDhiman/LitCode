// 112. Path Sum

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
    bool ok;
    
    int sm;
    
    void dfs(TreeNode* root, int c) {
        if (!root)  return;
        if ((root -> left == NULL) && (root -> right == NULL)){
            if (c + root -> val == sm){
                ok = 1;
            }
        }
        dfs(root -> left, c + root -> val);
        dfs(root -> right, c + root -> val);
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        ok = 0; sm = sum;
        dfs(root, 0);
        return ok;
    }
};
