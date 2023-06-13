//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
     void topo(int x,vector<int>&vis,stack<int>&st,vector<pair<int,int>>adj[]){
         vis[x]=1;
         for(auto vv:adj[x]){
             int child=vv.first;
             int wt=vv.second;
             if(vis[child]==0){
                 topo(child,vis,st,adj);
             }
         }
         st.push(x);
     }
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>>adj[n];
        for(auto x:edges){
            adj[x[0]].push_back({x[1],x[2]});
        }
        vector<int>vis(n+1,0);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                topo(i,vis,st,adj);
            }
        }
        vector<int>dist(n,1e9);
        dist[0]=0;
        while(!st.empty()){
            int x=st.top();
            st.pop();
            for(auto pp:adj[x]){
                int child=pp.first;
                int wt=pp.second;
                if(dist[child]>dist[x]+wt){
                    dist[child]=wt+dist[x];
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dist[i]==1e9)
              dist[i]=-1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends