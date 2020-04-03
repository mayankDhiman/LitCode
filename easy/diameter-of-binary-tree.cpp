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
    int ans;
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        foo(root);
        return ans - 1;
    }
    
    int foo(TreeNode* root) {
        if (!root)  return 0;
        int l = foo(root -> left);
        int r = foo(root -> right);
        ans = max(ans, l + r + 1);
        return 1 + max(l, r);
    }
};