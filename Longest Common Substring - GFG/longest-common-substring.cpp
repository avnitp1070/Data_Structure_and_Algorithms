//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
     int ans;
     int dp[1001][1001];
    int solve(int n,int m,string &s,string &t){
        if(m==0 || n==0){
            return 0;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        int cur=0;
        if(s[n-1]==t[m-1]){
            cur=1+solve(n-1,m-1,s,t);
        }
        solve(n-1,m,s,t);
        solve(n,m-1,s,t);
        ans=max(ans,cur);
        return dp[n][m]=cur;
    }
    int longestCommonSubstr (string s, string t, int n, int m)
    {
        // your code here
        ans=0;
        memset(dp,-1,sizeof(dp));
        solve(n,m,s,t);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends