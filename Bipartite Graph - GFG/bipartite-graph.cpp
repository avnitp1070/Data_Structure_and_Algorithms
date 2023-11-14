//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool dfs(int x,int c,vector<int>&vis,vector<int>&col,vector<int>adj[]){
        vis[x]=1;
        col[x]=c;
        for(auto child:adj[x]){
            if(vis[child]==0){
                if(dfs(child,c^1,vis,col,adj)==0){
                    return 0;
                }
            }
            else{
                if(col[x]==col[child]){
                    return 0;
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
	             if(dfs(i,0,vis,col,adj)==0){
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