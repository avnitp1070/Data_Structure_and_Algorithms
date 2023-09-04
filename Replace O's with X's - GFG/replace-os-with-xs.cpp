//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    bool isValid(int x,int y,int n,int m){
        if(x>=n || x<0 || y>=m || y<0){
            return 0;
        }
        return 1;
    }
    void dfs(int x,int y,vector<vector<char>> &mat,vector<vector<int>> &vis){
        vis[x][y]=1;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(isValid(nx,ny,mat.size(),mat[0].size()) && vis[nx][ny]==0 && mat[nx][ny]=='O'){
                dfs(nx,ny,mat,vis);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(mat[i][j]=='O')
                      dfs(i,j,mat,vis);
                }
            }
        }
        vector<vector<char>> ans=mat;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]){
                    ans[i][j]='O';
                }
                else{
                    ans[i][j]='X';
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