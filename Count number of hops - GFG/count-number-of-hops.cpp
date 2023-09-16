//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long
class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    ll dp[100001];
    ll mod=1e9+7;
    ll solve(int i,int n){
        if(i==n){
            return 1;
        }
        if(i>n){
            return 0;
        }
        if(dp[i]!=-1)
           return dp[i];
        int ans=solve(i+1,n)%mod;
        ans=(ans+solve(i+2,n))%mod;
        ans=(ans+solve(i+3,n))%mod;
        dp[i]=ans;
        return ans%mod;
    }
    
    long long countWays(int n)
    {
        
        memset(dp,-1,sizeof(dp));
        return solve(0,n);
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends