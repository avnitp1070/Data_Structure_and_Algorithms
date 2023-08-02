//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int dp[1001][1001];
    int solve(int i,int wt[],int val[],int w,int n){
        if(i>=n){
            return 0;
        }
        if(dp[i][w]!=-1){
            return dp[i][w];
        }
        int ans=0;
        if(wt[i]<=w){
            ans=max(val[i]+solve(i+1,wt,val,w-wt[i],n),solve(i+1,wt,val,w,n));
        }
        else{
            ans=solve(i+1,wt,val,w,n);
        }
        dp[i][w]=ans;
        return dp[i][w];
    }
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       memset(dp,-1,sizeof(dp));
       return solve(0,wt,val,w,n);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends