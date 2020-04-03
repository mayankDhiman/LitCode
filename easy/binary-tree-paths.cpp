// 257. Binary Tree Paths

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
    set <vector <int> > res;
    
    void doo(TreeNode* root, vector <int> cr) {
        if (!root){
            return;
        } 
        cr.emplace_back(root -> val);
        if ((root -> left == NULL) && (root -> right == NULL))
            res.insert(cr);        
        doo(root -> left, cr);
        doo(root -> right, cr);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        res.clear();
        vector <int> cr;
        doo(root, cr);
        vector <string> ret;                    
        for (auto i : res) {
            string t;
            for (auto j : i) {
                t += to_string(j);
                t += "->";                
            }
            string u = t.substr(0, t.size() - 2);   
            ret.push_back(u);
        }
        return ret;
    }
};