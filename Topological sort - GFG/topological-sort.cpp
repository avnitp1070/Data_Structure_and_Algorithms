//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	void dfs(int x,vector<int>&vis,vector<int> adj[],vector<int>&st){
	    vis[x]=1;
	    for(auto child:adj[x]){
	        if(vis[child]==0){
	            dfs(child,vis,adj,st);
	        }
	    }
	    st.push_back(x);
	}
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    vector<int>vis(n+1,0);
	    vector<int>st;
	   for(int i=0;i<n;i++){
	       if(vis[i]==0){
	           dfs(i,vis,adj,st);
	       }
	   }
	   
	   //vector<int>ans;
	   //while(!st.empty()){
	   //    ans.push_back(st.top());
	   //    st.pop();
	   //}
	   reverse(st.begin(),st.end());
	   return st;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends