//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
//   bool dfs(int node,vector<int> adj[],int vis[]){
//         vis[node]=1;
//         for(auto &it:adj[node]){
//             if(vis[it]==0){
//               if(dfs(it,adj,vis)==true){
//                   return true;
//              }
//             }
//              else if(vis[it]==1){
//                  return true;
//              }
//         }
//         vis[node]=2; // mark as safe node
//         return false;
//     }
//     vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
//         // code here
//         int vis[V]={0};
//         vector<int>ans;
//         for(int i=0;i<V;i++){
//             if(!vis[i]){
//                 dfs(i,adj,vis);
//             }
//         }
//         for(int i=0;i<V;i++){
//             if(vis[i]==2)
//               ans.push_back(i);
//         }
//         return ans;
//     }
    
    vector<int>topo(int n,vector<int>adj[]){
        queue<int>q;
        vector<int>vis(n,0);
        vector<int> tr[n];
        int outdeg[n]={0};
        for(int i=0;i<n;i++){
            for(auto x:adj[i]){
             outdeg[i]++;
             vis[i]=1;
             tr[x].push_back(i);
            }
        }
        
        for(int i=0;i<n;i++){
            if(outdeg[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            ans.push_back(x);
            for(auto child:tr[x]){
                outdeg[child]--;
                if(outdeg[child]==0){
                    q.push(child);
                }
            }
        }
        
        // for(int i=0;i<n;i++){
        //     if(vis[i]==1){
        //         ans.push_back(i);
        //     }
        // 
        
        //}
        sort(ans.begin(),ans.end());
        return ans;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        return topo(V,adj);
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends