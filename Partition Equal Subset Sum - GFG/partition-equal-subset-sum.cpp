//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int n,int sum,int arr[],vector<vector<int>>&dp){
        if(n==0){
            return 0;
        }
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }
        if(arr[n-1]<=sum){
            dp[n][sum]=max(arr[n-1]+solve(n-1,sum-arr[n-1],arr,dp),solve(n-1,sum,arr,dp));
        }
        else{
            dp[n][sum]=solve(n-1,sum,arr,dp);
        }
        return dp[n][sum];
    }
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(sum&1){
            return 0;
        }
        int p=sum/2;
        vector<vector<int>>dp(n+1,vector<int>(p+1,-1));
        return sum-2*solve(n,p,arr,dp)==0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends