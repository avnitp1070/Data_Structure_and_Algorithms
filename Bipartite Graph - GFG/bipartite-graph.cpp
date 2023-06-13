//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool bfs(int p,int c,vector<int>&col,vector<int>&vis,vector<int>adj[]){
        vis[p]=1;
        col[p]=c;
        queue<int>q;
        q.push(p);
        while(!q.empty()){
           int x=q.front();q.pop();
           
           for(auto child:adj[x]){
            if(vis[child]==0){
               vis[child]=1;
               col[child]=col[x]^1;
               q.push(child);
            }
            else{
                if(col[child]==col[x]){
                    return 0;
                }
            }
        }
        }
        
        return true;
    }
	bool isBipartite(int n, vector<int>adj[]){
	    vector<int>vis(n+1,0);
	    vector<int>col(n+1,-1);
	    for(int i=0;i<n;i++){
	        if(vis[i]==0){
	            if(bfs(i,0,col,vis,adj)==0){
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