// 111. Minimum Depth of Binary Tree

class Solution {
public:
    int ret = 2e9;
    
    void foo(TreeNode* root, int cd) {
        if (!root) return; 
        if ((root -> left == NULL) && (root -> right == NULL))
            ret = min(ret, cd);
        foo(root -> right, cd + 1);
        foo(root -> left, cd + 1);
    }
    
    int minDepth(TreeNode* root) {
        if (!root)  return 0;
        foo(root, 1);
        return ret;
    }
};
