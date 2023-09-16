class Solution {
public:
    
    int dx[4]={1,0,-1,0};
    int dy[4]={0,-1,0,1};
    
    bool isValid(int x,int y,int n,int m){
        if(x>=n || y>=m || x<0 || y<0){
            return 0;
        }
        return 1;
    }
   
    bool check(int mid,vector<vector<int>>& g){
        queue<pair<int,int>> q;
        int n=g.size();
        int m=g[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        q.push({0,0});
        vis[0][0]=1;
        while(!q.empty()) {
            auto node=q.front();
            q.pop();
            int x= node.first;
            int y= node.second;
            if(x==n-1 && y==m-1) 
                return 1;
            for(int i=0;i<4;i++) {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(isValid(nx,ny,n,m) && vis[nx][ny]==0){
                    if(abs(g[x][y]-g[nx][ny])> mid) 
                         continue;
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
        
        return false;
    }
    
    int minimumEffortPath(vector<vector<int>>& g) {
        
        int l = 0;
        int r= 1e9;
        int ans = INT_MAX;
        while(l<=r) {
            int mid =l+(r-l)/2;
            
            if(check(mid,g)) {
                r=mid-1;
                ans=min(ans,mid);
            } else {
                l=mid+1;
            }
        }
        
        return ans;
    }
};