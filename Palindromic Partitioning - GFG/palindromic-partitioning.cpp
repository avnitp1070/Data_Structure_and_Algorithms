//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[600][600];
    bool check(string &s){
        int n=s.size();
        for(int i=0;i<s.size()/2;i++){
            if(s[i]!=s[n-1-i]){
                return 0;
            }
        }
        return 1;
    }
    
    int solve(int i,int j,string &s){
        if(i>=j){
            return 0;
        }
        string p=s.substr(i,j-i+1);
        if(check(p)){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=INT_MAX;
        for(int k=i;k<j;k++){
            int left,right;
            if(dp[i][k]!=-1){
                left=dp[i][k];
            }
            else{
                left=solve(i,k,s);
            }
            
            if(dp[k+1][j]!=-1){
                right=dp[k+1][j];
            }
            else{
                right=solve(k+1,j,s);
            }
            int cur=1+left+right;
            ans=min(ans,cur); 
        }
        return dp[i][j]=ans;
    }
    int palindromicPartition(string str)
    {
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(0,str.size(),str);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends