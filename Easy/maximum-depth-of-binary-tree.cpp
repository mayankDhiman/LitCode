/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int _maxD(TreeNode* p){
    if (!p) return 0;
    if (!(p -> left) && !(p -> right))  return 1;
    
    return 1 + max( _maxD(p -> right), _maxD(p -> left));
    }

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return _maxD(root);
    }
};