//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod=1e9+7;
    int solve(int n,int sum,vector<int>&arr,vector<vector<int>>&dp){
        if(sum==0 && n==0){
            return 1;
        }
        if(n==0){
            return 0;
        }
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }
        if(arr[n-1]<=sum){
            dp[n][sum]=(solve(n-1,sum-arr[n-1],arr,dp)%mod+solve(n-1,sum,arr,dp)%mod)%mod;
        }
        else{
            dp[n][sum]=solve(n-1,sum,arr,dp)%mod;
        }
        return dp[n][sum];
    }
    
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int sum=0;
        for(auto x:arr){
            sum+=x;
        }
        int nsum=(sum-d)/2;
        if((sum-d)<0 || (sum-d)%2!=0){
            return 0;
        }
        
        vector<vector<int>>dp(n+1,vector<int>(nsum+1,-1));
        return solve(n,nsum,arr,dp)%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends