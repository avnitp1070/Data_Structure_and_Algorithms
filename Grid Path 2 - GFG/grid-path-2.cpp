//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   long long dp[100][100];
   int mod=1e9+7;
    long long solve(int i,int j,int n,int m,vector<vector<int>>& g){
        if(i>=n || j>=m){
            return 0;
        }
        if(g[i][j]==1){
            return 0;
        }
        if(i==n-1 && j==m-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        dp[i][j]=solve(i+1,j,n,m,g)+solve(i,j+1,n,m,g);
        return dp[i][j]%mod;
    }
    int totalWays(int n, int m, vector<vector<int>>& g) {
        // Code here
         memset(dp,-1,sizeof(dp));
        return solve(0,0,n,m,g);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends