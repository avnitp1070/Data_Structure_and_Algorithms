//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


#define ll long long

class Solution {
  public:
    ll dp[1001][1001];
     long long solve(int coins[],int n,int sum){
         if(sum==0){
             return 1;
         }
         if(n==0){
             return 0;
         }
         if(dp[n][sum]!=-1){
             return dp[n][sum];
         }
         
         if(coins[n-1]<=sum){
             dp[n][sum]=solve(coins,n,sum-coins[n-1])+solve(coins,n-1,sum);
         }
         else{
             dp[n][sum]=solve(coins,n-1,sum);
         }
         return dp[n][sum];
     }
    
    long long int count(int coins[], int n, int sum) {
         memset(dp,-1,sizeof(dp));
         return solve(coins,n,sum);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends