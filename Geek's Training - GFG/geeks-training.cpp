//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int dp[100001][3];
    
    int solve(int i,int b,vector<vector<int>>& p,int n){
        if(i>=n){
            return 0;
        }
        
        if(dp[i][b]!=-1){
            return dp[i][b];
        }
        dp[i][b]=0;
        for(int k=0;k<3;k++){
            if(k!=b){
                dp[i][b]=max(dp[i][b],p[i][b]+solve(i+1,k,p,n));
            }
        }
        return dp[i][b];
    }
    int maximumPoints(vector<vector<int>>& p, int n) {
        // Code here
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int k=0;k<3;k++){
          ans=max(ans,solve(0,k,p,n));
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends