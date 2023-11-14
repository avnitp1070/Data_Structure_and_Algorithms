//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int n, vector<int> adj[]) {
        queue<int>q;
        vector<int>in(n,0);
        for(int i=0;i<n;i++){
            for(auto child:adj[i]){
                in[child]++;
            }
        }
        for(int i=0;i<n;i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        
        while(!q.empty()){
            int x=q.front();
            q.pop();
            cnt++;
            for(auto child:adj[x]){
               in[child]--;
               if(in[child]==0){
                   q.push(child);
               }
            }
        }
        return cnt!=n?1:0;
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