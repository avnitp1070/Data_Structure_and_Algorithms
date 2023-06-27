//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     int dp[100001];
    int solve(int idx,vector<int> &h,int k){
        if(idx>=h.size()){
            return 1e9;
        }
        if(idx==h.size()-1){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        dp[idx]=1e9+7;
        for(int j=1;j<=k;j++){
            if(idx+j<h.size())
            dp[idx]=min(dp[idx],abs(h[idx]-h[idx+j])+solve(idx+j,h,k));
        }
        return dp[idx];
    }
    int minimizeCost(vector<int>& h, int n, int k) {
        // Code here
        memset(dp,-1,sizeof(dp));
        return solve(0,h,k);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends