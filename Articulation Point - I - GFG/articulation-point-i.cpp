//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  
    int time=0;
    void dfs(int x,int par,vector<int>&vis,vector<int>&in,vector<int>&low,vector<int>adj[],vector<int>&ans){
        vis[x]=1;
        low[x]=in[x]=time++;
         
         int cnt_child=0;
        for(auto child:adj[x]){
            if(child==par){
                continue;
            }
            if(vis[child]==1){
                low[x]=min(in[child],low[x]);
            }
            else{
                dfs(child,x,vis,in,low,adj,ans);
                low[x]=min(low[child],low[x]);

                if(low[child]>=in[x]  && par!=-1){
                    ans[x]=1;
                }
                cnt_child++;
            }
        }
        if(cnt_child>1 && par==-1){
            ans[x]=1;
        }
    }
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        // Code here
        vector<int>ans(n+1,0),res;
        vector<int>vis(n+1,0);
        vector<int>low(n+1,-1);
        vector<int>in(n+1,-1);
        dfs(0,-1,vis,in,low,adj,ans);
        for(int i=0;i<ans.size();i++){
            if(ans[i]==1){
                res.push_back(i);
            }
        }
        if(res.size()==0)
           return {-1};
        return res;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends