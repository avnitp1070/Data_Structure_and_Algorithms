//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define pii pair<int,pair<int,int>>
#define f first
#define se second

class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        // Code here
        vector<pair<int,int>>adj[n];
        vector<int>dist(n,1e9);
        for(auto x:flights){
            adj[x[0]].push_back({x[1],x[2]});
           // adj[x[1]].push_back({x[0],x[2]});
        }
        queue<pii>q;
        q.push({0,{src,0}});
        dist[src]=0;
        while(!q.empty()){
            auto p=q.front();q.pop();
            int stops=p.f;
            int x=p.se.f;
            int cost=p.se.se;
            if(stops>k){
                continue;
            }
            for(auto vv:adj[x]){
                int child=vv.f;
                int d=vv.se;
                if(dist[child]>cost+d && stops <= k){
                    dist[child]=cost+d;
                    q.push({stops+1,{child,dist[child]}});
                }
            }
        }
        if(dist[dst]==1e9){
            return -1;
        }
        return dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends