// 988. Smallest String Starting From Leaf

class Solution {
public:    
    string res;
    set <TreeNode*> vis;
    void dfs(TreeNode* r, string c) {
        if ((r -> left == NULL) && (r -> right == NULL) ){
            c += char('a' + r->val);
            reverse(c.begin(), c.end());
            cout << c << "\n";
            if (c < res) {
                res = c;
            }
            return;
        } 
        vis.insert(r);
        if (r -> left){
            if (vis.find(r -> left) == vis.end()){
                dfs(r -> left, c + char('a' + r->val) );
            }
        }
        if (r -> right){
            if (vis.find(r -> right) == vis.end()){
                dfs(r -> right, c + char('a' + r->val) );
            } 
        }
    }        

    string smallestFromLeaf(TreeNode* root) {
        res = string(8501, 'z');
        dfs(root, "");
        return res;
    }
};


