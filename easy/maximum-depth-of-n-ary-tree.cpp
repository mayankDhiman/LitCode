/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int ret = 1;
    
    void dfs(Node* r, int cr) {
        if ((r -> children).size() == 0) 
            ret = max(ret, cr);    
        for (auto c : r->children){
            dfs(c, cr + 1);
        }
    }
    
    int maxDepth(Node* root) {
        if (!root) return 0;
        dfs(root, 1);
        return ret;
    }
};
