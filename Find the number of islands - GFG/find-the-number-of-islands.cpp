//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define pii pair<int,int>
#define f first
#define se second
class Solution {
  public:
    // Function to find the number of islands.
    int dx[8]={-1,0,1,0,1,1,-1,-1};
    int dy[8]={0,1,0,-1,1,-1,-1,1};
    
    void bfs(int x,int y,vector<vector<char>>& grid){
        grid[x][y]='2';
        queue<pair<int,int>>q;
        q.push({x,y});  
        
        while(!q.empty()){
            auto vv=q.front();q.pop();
            int xp=vv.f;
            int yp=vv.se;
            for(int i=0;i<8;i++){
               int xx=xp+dx[i];
               int yy=yp+dy[i];
               if(xx>grid.size()-1 || xx<0 || yy>grid[0].size()-1 || yy<0){
                 continue;
                }
               if(grid[xx][yy]=='0' || grid[xx][yy]=='2'){
                 continue;
               }
               if(grid[xx][yy]=='1'){
                   grid[xx][yy]='2';
                q.push({xx,yy});
               } 
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,grid);
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