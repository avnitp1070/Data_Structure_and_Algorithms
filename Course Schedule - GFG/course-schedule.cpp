//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        vector<int>adj[n];
	    for(auto x:prerequisites){
	        adj[x[1]].push_back(x[0]);
	    }
	    vector<int>in(n,0);
	    for(int i=0;i<n;i++){
	        for(auto x:adj[i]){
	            in[x]++;
	        }
	    }
	    
	    vector<int>ans;
	    queue<int>q;
	    for(int i=0;i<n;i++){
	        if(in[i]==0){
	            q.push(i);
	        }
	    }
	    vector<int>p;
	    while(!q.empty()){
	        int x=q.front();
	        q.pop();
	        ans.push_back(x);
	        for(auto child:adj[x]){
	            in[child]--;
	            if(in[child]==0){
	                q.push(child);
	            }
	        }
	    }
	    return ans.size()<n?p:ans;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
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
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends