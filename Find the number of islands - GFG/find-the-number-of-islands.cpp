//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int dx[8]={-1,0,1,0,1,1,-1,-1};
    int dy[8]={0,1,0,-1,1,-1,-1,1};
    
    // void dfs(int x,int y,vector<vector<char>>& grid){
    //     if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() ){
    //         return;
    //     }
    //     if(grid[x][y]=='0' || grid[x][y]=='2'){
    //         return;
    //     }
    //     grid[x][y]='2';
    //     for(int i=0;i<4;i++){
    //         int xx=dx[i]+x;
    //         int yy=y+dy[i];
    //         dfs(xx,yy,grid);
    //     }
    // }
    
    void dfs(int x,int y,vector<vector<char>>&grid){
        if(x>grid.size()-1 || x<0 || y>grid[0].size()-1 || y<0){
            return;
        }
        if(grid[x][y]=='0' || grid[x][y]=='2'){
            return;
        }
        grid[x][y]='2';
        for(int i=0;i<8;i++){
            dfs(x+dx[i],y+dy[i],grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // int cnt=0;
        // for(int i=0;i<grid.size();i++){
        //     for(int j=0;j<grid[0].size();j++){
        //         if(grid[i][j]=='1'){
        //             cnt++;
        //             dfs(i,j,grid);
        //         }
        //     }
        // }
        // return cnt;
        
         int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,grid);
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