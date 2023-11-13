//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int x,int par,vector<int>&vis,vector<int>adj[]){
      vis[x]=1;
      for(auto child:adj[x]){
          if(vis[child]==0){
              if(dfs(child,x,vis,adj)==1){
                  return 1;
              }
          }
          else {
              if(child!=par){
                return 1;
               }
          }
      }
      return 0;
    }
    bool isCycle(int n, vector<int> adj[]) {
       vector<int>vis(n+1,0);
       for(int i=0;i<n;i++){
           if(vis[i]==0)
           if(dfs(i,-1,vis,adj)){
               return 1;
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