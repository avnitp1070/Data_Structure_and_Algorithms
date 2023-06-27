//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    	long long solve(ll i,ll b,int *arr,ll n,vector<vector<long long>>&dp){
	    if(i>=n){
	        return 0ll;
	    }
	    if(dp[i][b]!=-1){
	        return dp[i][b];
	    }
	    if(b){
	        dp[i][b]=solve(i+1,0,arr,n,dp);
	    }
	    else{
	        dp[i][b]=max(arr[i]+solve(i+1,1,arr,n,dp),solve(i+1,0,arr,n,dp));
	    }
	    return dp[i][b];
	}
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<vector<long long>>dp(n+1,vector<long long>(2,-1));
	    return (int)solve(0,0,arr,n,dp);
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends