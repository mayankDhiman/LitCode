// 129. Sum Root to Leaf Numbers

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
    set <TreeNode*> vis;
    
    void dfs(TreeNode* r, int cr) {
        if ((r -> left == NULL) && (r -> right == NULL) ){
            ret += (cr * 10 + (r -> val));
            return;
        } 
        vis.insert(r);
        if (r -> left){
            if (vis.find(r -> left) == vis.end()){
                dfs(r -> left, cr * 10 + (r -> val));
            }
        }
        if (r -> right){
            if (vis.find(r -> right) == vis.end()){
                dfs(r -> right, cr * 10 + (r -> val));
            } 
        }
    }
    
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        ret = 0;
        vis.clear();
        dfs(root, 0);
        return ret;
    }
};
