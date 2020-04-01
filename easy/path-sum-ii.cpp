// FIX YOURSELF

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
    int _sum;
    
    int ps(TreeNode* root, int sm){
        if (_sum == sm) {
            return 1;
        }
        
        if (!root){            
            return (sm == _sum);
        }
        
        return 
            
        ps (root -> left, sm) +
        ps (root -> left, sm + (root -> val)) +
        ps (root -> right, sm) +
        ps (root -> right, sm + (root -> val));
        
    }
    
    int pathSum(TreeNode* root, int sum) {
        _sum = sum;
        return ps(root, 0);    
    }
};
