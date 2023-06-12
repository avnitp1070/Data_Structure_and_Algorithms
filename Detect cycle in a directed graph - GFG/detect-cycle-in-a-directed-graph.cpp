//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(int x,vector<int>&vis,vector<int> adj[]){
        vis[x]=1;
        for(auto child:adj[x]){
            if(vis[child]==0){
                if(dfs(child,vis,adj)){
                    return 1;
                }
            }
            else{
                if(vis[child]==1){
                    return 1;
                }
            }
        }
        vis[x]=2;
        return 0;
    }
    bool isCyclic(int n, vector<int> adj[]) {
        vector<int>vis(n+1,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                if(dfs(i,vis,adj)){
                    return 1;
                }
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends