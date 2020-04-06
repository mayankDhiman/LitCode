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
    int hei(TreeNode* root) {
        if (!root)  return 0;
        return 1 + hei(root -> left);
    }
    
    
    int countNodes(TreeNode* root) {
        if (!root)  return 0;
        int h = hei(root);
        if (hei(root -> right) == h - 1) {
            return (1<<h - 1) + countNodes(root -> right);
        }
        else{
            return (1<<(h - 1) - 1) + countNodes(root -> left);
        }
    }
};
