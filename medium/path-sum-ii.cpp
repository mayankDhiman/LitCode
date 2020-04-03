// 113. Path Sum II

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
    int t;
    vector < vector <int> > ret;
    set <TreeNode*> vis;
    
    void dfs(TreeNode* r, vector <int> c) {
        if ((r -> left == NULL) && (r -> right == NULL) ){
            c.emplace_back(r -> val);
            for (auto x : c)    cout << x << " ";   cout << "\n";
            if (accumulate(c.begin(), c.end(), 0) == t) {
                ret.push_back(c);
            }
            return;
        }
        vis.insert(r);
        if (r -> left){
            if (vis.find(r -> left) == vis.end()){
                vector <int> c_ = c;
                c_.emplace_back(r -> val);
                dfs(r -> left, c_);
            }
        }
        if (r -> right){
            if (vis.find(r -> right) == vis.end()){
                vector <int> c_ = c;
                c_.emplace_back(r -> val);
                dfs(r -> right, c_);
            } 
        }
    }        
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        t = sum;    vis.clear();    ret.clear();
        if (!root)  return ret;
        vector <int> c; dfs(root, c);
        return ret;
    }
};



