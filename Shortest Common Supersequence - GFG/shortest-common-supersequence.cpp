//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int dp[101][101];
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
    int shortestCommonSupersequence(string s, string t, int n, int m)
    {
        //code here
        memset(dp,-1,sizeof(dp));
        int k=solve(n,m,s,t);
        return n+m-k;
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends