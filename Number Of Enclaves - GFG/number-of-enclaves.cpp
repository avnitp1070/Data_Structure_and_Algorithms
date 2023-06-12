//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                  if(i==0 || i==n-1 || j==0 || j==m-1 )
                  q.push({i,j}), vis[i][j]=1;;
                }
            }
        }
        
        while(!q.empty()){
            auto p=q.front();q.pop();
            int a=p.first;
            int b=p.second;
            for(int k=0;k<4;k++){
            int x=a+dx[k];
            int y=b+dy[k];
            if(x<0 || x>=n || y<0 || y>=m || vis[x][y]==1 || grid[x][y]==0){
            	continue;
            	}
            vis[x][y]=1;
            q.push({x,y});
        }
        }
        
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0){
                  if(grid[i][j]==1)
                    cnt++;
                }
            }
        }
        return cnt;
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends