//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[1001][1001];
    int solve(int i,int w,int val[],int wt[],int n){
        if(i>=n){
            return 0;
        }
        if(dp[i][w]!=-1){
            return dp[i][w];
        }
        int ans=0;
        if(wt[i]<=w){
            ans=max(val[i]+solve(i,w-wt[i],val,wt,n),solve(i+1,w,val,wt,n));
        }
        else{
            ans=solve(i+1,w,val,wt,n);
        }
        return dp[i][w]=ans;
    }
    
    int knapSack(int n, int w, int val[], int wt[])
    {
        memset(dp,-1,sizeof(dp));
         return solve(0,w,val,wt,n);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends