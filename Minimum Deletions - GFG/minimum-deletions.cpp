//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

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
    int minimumNumberOfDeletions(string s) { 
        // code here
        memset(dp,-1,sizeof(dp));
        string t=s;
        reverse(s.begin(),s.end());
        return s.size()-solve(s.size(),s.size(),s,t);
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends