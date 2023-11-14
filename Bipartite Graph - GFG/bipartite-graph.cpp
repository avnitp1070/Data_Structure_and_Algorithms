//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool bfs(int sx,int c,vector<int>&vis,vector<int>&col,vector<int>adj[]){
       queue<pair<int,int>>q;
       q.push({sx,c});
       vis[sx]=1;
       col[sx]=c;
       while(!q.empty()){
           auto p=q.front();q.pop();
           int x=p.first;
           for(auto child:adj[x]){
               if(vis[child]==0){
                   q.push({child,col[x]^1});
                   col[child]=col[x]^1;
                   vis[child]=1;
               }
               else {
                   if(col[child]==col[x]){
                       return 0;
                   }
               }
           }
       }
       return 1;
    }
	bool isBipartite(int n, vector<int>adj[]){
	    // Code here
	     vector<int>vis(n+1,0),col(n+1,0);
	     for(int i=0;i<n;i++){
	         if(vis[i]==0){
	             if(bfs(i,0,vis,col,adj)==0){
	                 return 0;
	             }
	         }
	     }
	     return 1;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends