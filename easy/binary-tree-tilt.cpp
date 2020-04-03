// 563. Binary Tree Tilt

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
    int foo(TreeNode* root) {
        if (!root) return 0;
        return (root -> val) + foo(root -> left) + foo(root -> right);
    }
        
    void doo(TreeNode* root) {
        if (!root)  return;
        ans += abs(foo(root -> left) - foo(root -> right));           
        doo(root -> left);
        doo(root -> right);
    }
    
    int findTilt(TreeNode* root) {
        ans = 0;
        doo(root);
        return ans;
    }
};