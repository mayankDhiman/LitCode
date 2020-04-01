/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool _issym(TreeNode* p, TreeNode* q) 
{
    if (!p && !q)   return true;
    if ((p && !q)  or (!p && q))    return false;
    
    
    return (
               (_issym(p -> left, q -> right)) &&
               (_issym(p -> right, q -> left)) &&
               (p -> val == q -> val)
           ); 
}


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return _issym(root, root);   
    }
};