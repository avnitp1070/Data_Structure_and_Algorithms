//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    
    bool isValid(int x,int y,int n,int m){
        if(x<0 || y<0 || x>=n || y>=m){
            return 0;
        }
        return 1;
    }
    
    void dfs(int x,int y,vector<vector<int>>& vis,vector<vector<int>>& g,int x0,int y0,vector<pair<int,int>>&v){
        vis[x][y]=1;
        v.push_back({x-x0,y-y0});
        
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(isValid(nx,ny,g.size(),g[0].size())==0){
                continue;
            }
            if(vis[nx][ny]==0 && g[nx][ny]==1){
                dfs(nx,ny,vis,g,x0,y0,v);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        vector<vector<int>>vis(n+1,vector<int>(m+1,0));
        set<vector<pair<int,int>>>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && g[i][j]==1){
                    vector<pair<int,int>>v;
                    dfs(i,j,vis,g,i,j,v);
                    st.insert(v);
                }
            }
        }
        return (int)st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends