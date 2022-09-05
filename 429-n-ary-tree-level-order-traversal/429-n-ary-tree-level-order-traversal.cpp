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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> answer;
        if(root == NULL) return answer;
        queue<Node*> q; q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            vector<int> curr;
            while(sz--) {
                Node* f = q.front(); q.pop();
                curr.push_back(f->val);
                for(Node* u: f->children) {
                    if(u != NULL) q.push(u);
                }
            }
            answer.push_back(curr);
        }
        return answer;
    }
};