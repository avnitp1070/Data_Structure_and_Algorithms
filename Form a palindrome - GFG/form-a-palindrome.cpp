//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int dp[501][501];
    
    int solve(int n,int m,string &s,string &t){
        if(n==0 || m==0){
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
    int findMinInsertions(string s){
        string t=s;
        reverse(t.begin(),t.end());
        memset(dp,-1,sizeof(dp));
        return s.size()-solve(s.size(),t.size(),s,t);
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends