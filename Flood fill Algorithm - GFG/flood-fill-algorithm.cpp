//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    
    void dfs(int x,int y,vector<vector<int>>& image,vector<vector<int>>&ans,int inicol,int col){
        if(x<0 || x>=image.size() || y<0 || y>=image[0].size() || image[x][y]!=inicol){
            return;
        }
        if(ans[x][y]==col){
            return;
        }
        ans[x][y]=col;
        for(int i=0;i<4;i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            dfs(xx,yy,image,ans,inicol,col);
        }
    }
    
    void bfs(int xx,int yy,vector<vector<int>>& image,vector<vector<int>>&ans,int inicol,int col){
        queue<pair<int,int>>q;
        q.push({xx,yy});
        ans[xx][yy]=col;
        while(!q.empty()){
          auto p=q.front();q.pop();
          int a=p.first;
          int b=p.second;
          for(int i=0;i<4;i++){
            int x=a+dx[i];
            int y=b+dy[i];
            
            if(x<0 || x>=image.size() || y<0 || y>=image[0].size() || image[x][y]!=inicol){
             continue;
             }
             if(ans[x][y]==col){
                 continue;
             }
             ans[x][y]=col;
             q.push({x,y});
        }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        vector<vector<int>> ans=image;
        bfs(sr,sc,image,ans,image[sr][sc],newColor);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends