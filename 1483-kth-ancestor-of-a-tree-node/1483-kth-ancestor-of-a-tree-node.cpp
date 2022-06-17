class TreeAncestor {
    int l;
    vector<vector<int>> up;
    
public:
    TreeAncestor(int n, vector<int>& parent)
    {
        l = ceil(log2(n));
        up.assign(n, vector<int>(l + 1));
            
        for(int j=0; j<n; j++)
            up[j][0] = parent[j];
        
        for(int i=1; i<=l; i++) {
            for(int j=0; j<n; j++) {
                if(up[j][i-1] == -1) {
                    up[j][i] = -1;
                    continue;
                }
                up[j][i] = up[up[j][i-1]][i-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0; i<=l; i++) {
            if((k >> i) & 1)
                node = up[node][i];
            if(node == -1) return -1;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */