//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int dp[505][505];
    int solve(int i,int j,vector<vector<int>> &mat){
        if(i>=mat.size() || j<0 || j>=mat[0].size()){
            return 0;
        }
        // if(i==mat.size()-1){
        //     return mat[i][j];
        // }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        dp[i][j]=mat[i][j]+max({solve(i+1,j-1,mat),solve(i+1,j,mat),solve(i+1,j+1,mat)});
        return dp[i][j];
    }
    
    int maximumPath(int n, vector<vector<int>> mat)
    {
        // code here
        memset(dp,-1,sizeof(dp));
        int ans=0;
        int m=mat[0].size();
        for(int i=0;i<m;i++){
            ans=max(ans,solve(0,i,mat));
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends