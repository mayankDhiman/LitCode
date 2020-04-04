// 110. Balanced Binary Tree

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
    int goo(TreeNode* root) {
        if (!root) return 0;
        int l = goo(root -> left);
        int r = goo(root -> right);
        if (r == -1 or l == -1)    return -1;
        return (abs(l - r) <= 1) ? (1 + max(l, r)) : -1;
    }
    bool isBalanced(TreeNode* root) {
        return (goo(root) != -1);
    }
};
