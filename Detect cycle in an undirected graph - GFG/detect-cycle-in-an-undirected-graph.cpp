//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int x, vector<int>&vis,vector<int> adj[]){
        queue<pair<int,int>>q;
        vis[x]=1;
        q.push({x,-1});
        while(!q.empty()){
            auto p=q.front();
            int node=p.first;
            int par=p.second;
            q.pop();
            for(auto child:adj[node]){
                if(vis[child]==0){
                    vis[child]=1;
                    q.push({child,node});
                }
                else{
                    if(child!=par){
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>vis(V+1,0);
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                if(bfs(i,vis,adj)){
                    return 1;
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends