class Solution:
    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        g = [[] for i in range(n)]
        ans = list(list())
        
        for u, v in connections:
            g[u].append(v)
            g[v].append(u)
            
        vis = [False] * n
        disc = [(1e9)] * n
        low = [(1e9)] * n
        parent = [int(-1)] * n
        
        def dfs(u, timestamp):
            vis[u] = True
            disc[u] = timestamp
            low[u] = timestamp
            timestamp += 1
            
            for v in g[u]:
                if vis[v] == False:
                    parent[v] = u
                    dfs(v, timestamp)
                    low[u] = min(low[u], low[v])
                    
                    if low[v] > disc[u]:
                        ans.append(list({u, v}))
                
                elif parent[u] != v:
                    low[u] = min(low[u], disc[v])
        
        dfs(0, 1)
                        
        return ans
        