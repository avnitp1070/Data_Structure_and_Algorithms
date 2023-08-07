//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
    int solve(int n,int arr[],int sum,vector<vector<int>>&dp){
        if(n==0){
            return 0;
        }
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }
        if(arr[n-1]<=sum){
            dp[n][sum]=max(arr[n-1]+solve(n-1,arr,sum-arr[n-1],dp),solve(n-1,arr,sum,dp));
        }
        else{
            dp[n][sum]=solve(n-1,arr,sum,dp);
        }
        return dp[n][sum];
    }
    
	int minDifference(int arr[], int n)  {
	    int sum=0;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	    }
	   
	    vector<vector<int>>dp(n+1,vector<int>(sum/2+1,-1));
	    return abs(sum-2*solve(n,arr,sum/2,dp));
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends