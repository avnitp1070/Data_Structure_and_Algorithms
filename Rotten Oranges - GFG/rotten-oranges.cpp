//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define f first
#define se second

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,-1,1};
    
    bool isValid(int x,int y,int n,int m){
        if(x<0 || y<0 || x>=n || y>=m){
            return 0;
        }
        return 1;
    }
    
    void bfs(int sx,int sy,vector<vector<int>>&dist,vector<vector<int>>& g){
        queue<pair<int,int>>q;
        q.push({sx,sy});
        dist[sx][sy]=0;
        
        while(!q.empty()){
            auto p=q.front();q.pop();
            int x=p.f;
            int y=p.se;

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                
                if(isValid(nx,ny,g.size(),g[0].size())==0 || g[nx][ny]==0 || g[nx][ny]==2){
                    continue;
                }
                if(dist[nx][ny]>1+dist[x][y]){
                    dist[nx][ny]=1+dist[x][y];
                    q.push({nx,ny});
                }
                
            }
        }
    }
    
    int orangesRotting(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==2){
                    dist[i][j]=0;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==2){
                    bfs(i,j,dist,g);
                }
            }
        }
        int ans=0;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]!=0){
                    ans=max(ans,dist[i][j]);
                }
            }
        }
        return ans!=1e9?ans:-1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends