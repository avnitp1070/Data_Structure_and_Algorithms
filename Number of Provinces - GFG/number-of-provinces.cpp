//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    void dfs(int x,vector<int>&vis,vector<int>adj[]){
        vis[x]=1;
        queue<int>q;
        q.push(x);
        while(!q.empty()){
            auto u=q.front();q.pop();
            for(auto child:adj[u]){
                if(vis[child]==0){
                    vis[child]=1;
                    q.push(child);
                }
            }
        }
    }
    int numProvinces(vector<vector<int>> v, int V) {
        int cnt=0;
        int n=v.size();
         vector<int>adj[n+1];
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>vis(n+1,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                cnt++;
                dfs(i,vis,adj);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends