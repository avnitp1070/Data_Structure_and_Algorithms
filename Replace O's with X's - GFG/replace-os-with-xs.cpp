//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
      int dx[4]={-1,0,1,0};
     int dy[4]={0,1,0,-1};
    void dfs(int i, int j,int n, int m, vector<vector<int>> &vis,vector<vector<char>> &mat){
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x<0 || x>=n || y<0 || y>=m || vis[x][y]==1 || mat[x][y]=='X'){
            	continue;
            	}
            dfs(x,y,n,m,vis,mat);
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
         
    vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O' && vis[i][j]==0){
                  if(i==0 || i==n-1 || j==0 || j==m-1 )
                  dfs(i,j,n,m,vis,mat);
                }
            }
        }
        vector<vector<char>>ans(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0){
                  ans[i][j]='X';
                }
                else{
                    ans[i][j]='O';
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends