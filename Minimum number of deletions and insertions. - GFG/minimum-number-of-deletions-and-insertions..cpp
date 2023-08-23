//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int dp[1001][1001];
	int solve(int n,int m,string &s,string &t){
	    if(n==0 || m==0){
	        return 0;
	    }
	    if(dp[n][m]!=-1){
	        return dp[n][m];
	    }
	    if(s[n-1]==t[m-1]){
	        dp[n][m]=1+solve(n-1,m-1,s,t);
	    }
	    else{
	        dp[n][m]=max(solve(n-1,m,s,t),solve(n,m-1,s,t));
	    }
	    return dp[n][m];
	}
	int minOperations(string s, string t) 
	{ 
	    // Your code goes here
	    memset(dp,-1,sizeof(dp));
	    int n=s.size();
	    int m=t.size();
	    int p=solve(n,m,s,t);
	    return n+m-2*p;
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends