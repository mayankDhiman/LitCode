/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool _issame(TreeNode* p, TreeNode* q) {
    if ( (!p) && q)    return false;
    if (p && (!q) )    return false;
    if ( (!p) && (!q) )   return true;
    
    if ( (p -> val == q -> val)  &&
         (_issame(p -> right, q -> right)) &&
         (_issame(p -> left, q -> left))){
        return true;
    }
    return false;
}

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return _issame(p, q);    
    }
};