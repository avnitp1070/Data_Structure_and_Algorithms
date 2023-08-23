//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

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
    int longestPalinSubseq(string s) {
        //code here
        memset(dp,-1,sizeof(dp));
        string t=s;
        reverse(t.begin(),t.end());
        return solve(s.size(),t.size(),s,t);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends