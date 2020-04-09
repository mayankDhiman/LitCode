// 1315. Sum of Nodes with Even-Valued Grandparent

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
    int ret;
    
    void dfs(TreeNode* root) {
        if (!root) return;
        
        if (root -> val % 2 == 0) {
            if (root -> left){
                if (root -> left -> left)   ret += root -> left -> left -> val;
                if (root -> left -> right)   ret += root -> left -> right -> val;                
            }
            if (root -> right){
                if (root -> right -> left)   ret += root -> right -> left -> val;
                if (root -> right -> right)   ret += root -> right -> right -> val;                
            }
            
        }
        
        dfs(root -> left);
        dfs(root -> right);
    }    
    int sumEvenGrandparent(TreeNode* root) {
        ret = 0;
        dfs(root);
        return ret;
    }
};
