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
    
//     bool check(int mid,vector<vector<int>>&vis,vector<vector<int>>&g){
        
//     }
    
    int minimumEffortPath(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();

        vector<vector<int>>dp(n,vector<int>(m, 1e9));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, 0}); // First item is effort, second is row * 100 + col
        while (!pq.empty()) {
           int effort = pq.top().first;
           int x = pq.top().second / 100, y = pq.top().second % 100;
           pq.pop();

           if (x == n - 1 && y == m - 1) 
               return effort;
           if (effort >= dp[x][y])
               continue;
           dp[x][y] = effort;

           for (int i = 0; i < 4; i++) {
                int nx=x+dx[i],ny=y+dy[i];
                
               if(isValid(nx,ny,n,m)){
                   int n_effort = max(effort, abs(g[x][y] - g[nx][ny]));
                   pq.push({n_effort, nx * 100 + ny});
               }
          }
        }
       return -1;
       
    }
};