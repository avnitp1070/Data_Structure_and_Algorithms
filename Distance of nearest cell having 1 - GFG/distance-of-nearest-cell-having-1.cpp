//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    
    bool isValid(int x,int y,int n,int m){
        if(x<0 || y<0 || x>=n || y>=m){
            return 0;
        }
        return 1;
    }
	vector<vector<int>>nearest(vector<vector<int>>g)
	{
	    // Code here
	    int n=g.size();
	    int m=g[0].size();
	    vector<vector<int>>dist(n,vector<int>(m,1e9));
	    queue<pair<int,int>>q;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(g[i][j]==1){
	                dist[i][j]=0;
	                q.push({i,j});
	            }
	        }
	    }
	    while(!q.empty()){
	        auto p=q.front();
	        int x=p.first;
	        int y=p.second;
	        q.pop();
	        for(int i=0;i<4;i++){
	           int nx=x+dx[i];
	           int ny=y+dy[i];
	           if(isValid(nx,ny,n,m) &&  dist[nx][ny]>1+dist[x][y]){
	               dist[nx][ny]=1+dist[x][y];
	               q.push({nx,ny});
	           }
	        }
	    }
	    
	    return dist;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends