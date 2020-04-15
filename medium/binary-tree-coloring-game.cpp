// 1145. Binary Tree Coloring Game


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
    int xx, cn;
    TreeNode* loc;
    
    void foo(TreeNode* root) {
        if (!root)  return;
        cn += 1;
        foo(root -> right);
        foo(root -> left);
    }
    
    void lc(TreeNode* root) {
        if (!root)  return;
        if ((root -> val) == xx){
            loc = root;
        }
        lc(root -> left);
        lc(root -> right);
    }
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        bool ok = 0;
        xx = x;     loc = NULL;     lc(root);   
        cn = 0;     foo(loc);
        if (cn <= n/2)   return 1;
        cn = 0;     foo(loc -> left);
        if (cn > n/2)   return 1;
        cn = 0;     foo(loc -> right);
        if (cn > n/2)   return 1;        
        return 0;
    }
};
