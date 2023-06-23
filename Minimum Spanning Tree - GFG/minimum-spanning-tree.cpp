//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define pii pair<int,int>
class Solution
{
	public:
	
	vector<int>parent;
 void make_set(int n){
    parent.resize(n+5); 
    for(int i=0;i<n+5;i++){
     parent[i]=i;
 }
}
int find(int x){
       if( parent[x] == x) {
            return x;
        }
       return parent[x]=find(parent[x]);
    }

bool union_set(int x,int y){
        int p=find(x);
        int q=find(y);
        if(p==q){
            return true;
        }
        parent[p]=q;
        return false;
    }
    
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int,pair<int,int>>>v;
        int sum=0;
        for(int i=0;i<n;i++){
            for(auto x:adj[i]){
                v.push_back({x[1],{i,x[0]}});
            }
        }
        make_set(n);
        sort(v.begin(),v.end());
        
        for(auto x:v){
            int a=x.second.first;
            int b=x.second.second;
            if(find(a)==find(b)){
                continue;
            }
            sum+=x.first;
            union_set(a,b);
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends