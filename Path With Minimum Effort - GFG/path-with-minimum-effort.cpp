//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define pii pair<int,pair<int,int>>
#define f first
#define se second

class Solution {
  public:
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    int MinimumEffort(vector<vector<int>>& h) {
        // Code here
        int n=h.size();
        int m=h[0].size();
         vector<vector<int>>dist(n,vector<int>(m,1e9));
         priority_queue <pii, vector<pii>, greater<pii>> pq;
         pq.push({0,{0,0}});
         dist[0][0]=0;
         
         while(!pq.empty()){
             auto k=pq.top();
             pq.pop();
             int x=k.se.f;
             int y=k.se.se;
             int diff=k.f;
             for(int i=0;i<4;i++){
                 int xx=dx[i]+x;
                 int yy=dy[i]+y;
                 if(xx<0 || xx>=n || yy<0 || yy>=m){
                     continue;
                 }
                 int d=max(diff,abs(h[x][y]-h[xx][yy]));
                 if(dist[xx][yy]>d){
                     dist[xx][yy]=d;
                     pq.push({dist[xx][yy],{xx,yy}});
                 }
             }
         }
        return dist[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends