class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        # Finding parents using BFS
        vector <int> adj[1000];
        vector <bool> used(1000, 0);
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* x = q.front();
            q.pop();
            if (x -> right != NULL){
                if (!used[(x -> right) -> val]){
                    q.push(x -> right);
                    adj[x->val].push_back(x->right->val);
                    adj[x->right->val].push_back(x->val);
                }
            }
            if (x -> left != NULL){
                if (!used[(x -> left) -> val]){
                    q.push(x -> left);
                    adj[x->val].push_back(x->left->val);
                    adj[x->left->val].push_back(x->val);
                }
            }
        }
                
        
        # BFS starting from the target point
        vector <int> result;    int t = target -> val;
        queue <int> qq; qq.push(t);
        int d[1000] = {INT_MAX}, u[1000] = {false};    d[t] = 0;     u[t] = true;
        while(!qq.empty()){
            int x = qq.front();  qq.pop();
            for (auto y : adj[x]){
                if (!u[y]){
                    u[y] = 1;
                    qq.push(y);
                    d[y] = d[x] + 1;
                }
            }          
        }
        
        for (int i = 0; i < 500; i ++){
            if (d[i] == K && u[i]){
                result.push_back(i);
            }
        }         
        
        return result; 
    }
};
