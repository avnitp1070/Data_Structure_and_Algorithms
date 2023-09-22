class Solution {
public:
    int dp[101][10001];

    int solve(int n,int m,string &s,string &t){
       if(n==0|| m==0){
           return 0;
       }

       if(dp[n][m]!=-1){
           return dp[n][m];
       }
       int ans=0;
       if(s[n-1]==t[m-1]){
           ans=1+solve(n-1,m-1,s,t);
       }
       else{
           ans=max(solve(n-1,m,s,t),solve(n,m-1,s,t));
       }
       return dp[n][m]=ans;
    }
    bool isSubsequence(string s, string t) {
        memset(dp,-1,sizeof(dp));
        if(solve(s.size(),t.size(),s,t)==s.size()){
            return 1;
        }
        return 0;
    }
};