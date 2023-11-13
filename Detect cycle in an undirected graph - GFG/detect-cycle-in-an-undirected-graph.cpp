//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    vector<int>parent;
    void make_set(int n){
        parent.resize(n+5);
        for(int i=0;i<n+5;i++){
            parent[i]=i;
        }
    }
    
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    
    bool union_set(int x,int y){
       x=find(x);
       y=find(y);
       
       if(x==y){
           return true;
       }
       parent[x]=y;
       return false;
    }
    
    bool isCycle(int n, vector<int> adj[]) {
       make_set(n);
       vector<int>vis(n+1,0);
        for(int i=0;i<n;i++){
            int x=i;
            vis[i]=1;
            for(auto y:adj[x]){
                
                if(find(x)==find(y)){
                  if(y>i)
                    return 1;
                }
                bool b=union_set(x,y);
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