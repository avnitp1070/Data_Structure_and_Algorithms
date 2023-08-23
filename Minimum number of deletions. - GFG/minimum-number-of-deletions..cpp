//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends

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
int minDeletions(string s, int n) { 
    //complete the function here 
    memset(dp,-1,sizeof(dp));
    string t=s;
    reverse(t.begin(),t.end());
    int p=solve(s.size(),t.size(),s,t);
    return s.size()-p;
} 