// 637. Average of Levels in Binary Tree

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector <double> ret;
        set <TreeNode*> used; 
        queue <TreeNode*> q;
        q.push(root);
        used.insert(root);
        while (!q.empty()){            
            long long sm = 0, cn = q.size(); int rp = cn;
            while (rp --){
                TreeNode* x = q.front();
                sm += (x -> val);
                q.pop();    
                if (x -> left){
                    if (used.find(x -> left) == used.end()){   
                        used.insert(x -> left);
                        q.push(x -> left);
                    }                
                }
                if (x -> right){
                    if (used.find(x -> right) == used.end()){
                        used.insert(x -> right);
                        q.push(x -> right);
                    }
                }                    
            }
            ret.push_back(sm*1.0/cn);
        }
        return ret;
    }
};