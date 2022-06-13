// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class SCC {
	int n;
	vector<vector<int>> g;
	vector<vector<int>> rg; // reverseGraph to perform dfs2
	vector<vector<int>> scc;
	vector<bool> vis;
	stack<int> st;
	vector<int> component;
public:
	SCC(vector<vector<int>> _g, int _n) {
		g = _g;
		n = _n;
		rg = vector<vector<int>>(n+1);
		for(int i=1; i<=n; i++) {
			for(int j : g[i])
				rg[j].push_back(i);
		}
	}
	void dfs1(int x) {
		vis[x] = true;
		for(int y : g[x]) {
			if(!vis[y])
				dfs1(y);
		}
		st.push(x);
	}
	void dfs2(int x) {
		vis[x] = true;
		for(int y : rg[x]) {
			if(!vis[y])
				dfs2(y);
		}
		component.push_back(x);
	}

	void findSCC() { // nodes from 1...n
		vis = vector<bool>(n+1, false);
		for(int i=1; i<=n; i++) {
			if(!vis[i])
				dfs1(i);
		}

		vis = vector<bool>(n+1, false);
		while(!st.empty()) {
			if(!vis[st.top()]) {
				component.clear();
				dfs2(st.top());
				scc.push_back(component);
			}
			// cout << st.top() << " ";
			st.pop();
		}
	}

	void printSCC() {
		for(auto v : scc) {
			for(int x : v)
				cout << x << " ";
			cout << endl;
		}
	}
	
	int no_of_SCC(){
	    return scc.size();
	}

	// extra function for to tell the number of strongly connected components
	// and for each node i, which component does it belong.
    void getAnswer() {
        cout << scc.size() << endl; // number of kingdoms
        vector<int> ans(n+1, 0);
        int kingdom = 0;
        for(auto &v : scc) {
            kingdom++;
            for(int x : v) {
                ans[x] = kingdom; // which kindom does x belongs
            }
        }
        for(int i=1; i<=n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
};

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        vector<vector<int>> g(V+1);
        for(int i=0; i<V; i++) {
            for(int x : adj[i]) {
                g[i+1].push_back(x+1);
            }
        }
        SCC obj(g, V);
        obj.findSCC();
        return obj.no_of_SCC();
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends