//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int dx[8]={1,-1,0,0,1,-1,1,-1};
    int dy[8]={0,0,1,-1,1,1,-1,-1};
    bool isValid(int x,int y,int n,int m){
        if(x<0 || x>=n || y<0 || y>=m){
            return 0;
        }
        return 1;
    }
    
    void dfs(int x,int y,vector<vector<int>>&vis,vector<vector<char>>&g){
        vis[x][y]=1;
        for(int i=0;i<8;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(isValid(nx,ny,g.size(),g[0].size())==0){
                continue;
            }
            if(vis[nx][ny]==0 && g[nx][ny]=='1'){
                dfs(nx,ny,vis,g);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& g) {
        vector<vector<int>>vis(g.size()+1,vector<int>(g[0].size()+1,0));
        int cnt=0;
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                if(vis[i][j]==0 && g[i][j]=='1'){
                    cnt++;
                    dfs(i,j,vis,g);
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends