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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector < vector <int> >  result;
        
        queue <TreeNode*> q;
        set <TreeNode*> used;
        map <TreeNode*, int> d;
        map <int, vector <int> > _r;
        d[root] = 0;
        
        if (root){
            q.push(root);
            used.insert(root);
        }
        
        while (!q.empty()) {
            TreeNode* v = q.front();
            q.pop();
            if (v)   _r[d[v]].push_back(v -> val);
            if (used.find(v -> left) == used.end()  && (v -> left)) {
                used.insert(v -> left);
                q.push(v -> left);
                d[v -> left] = d[v] + 1;
            }  
            if ( used.find(v -> right) == used.end() && (v -> right)) {
                used.insert(v -> right);
                q.push(v -> right);
                d[v -> right] = d[v] + 1;
            }
        }
        
        for (auto i : _r){
            result.push_back(i.second);
        }
        reverse(result.begin(), result.end());
        
        return result;
    }
};