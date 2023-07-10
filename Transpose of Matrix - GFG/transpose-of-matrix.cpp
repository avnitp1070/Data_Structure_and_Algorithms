//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public:  
    //Function to find transpose of a matrix.
    void transpose(vector<vector<int> >& mat, int n)
    { 
        // code here 
        vector<vector<int>>v=mat;
        for(int i=0;i<mat.size();i++){
            //vector<int>a;
            for(int j=0;j<mat[0].size();j++){
                mat[i][j]=v[j][i];
            }
           // v.push_back(a);
        }
        for(int i=0;i<mat.size();i++){
            //vector<int>a;
            for(int j=0;j<mat[0].size();j++){
                v[i][j]=mat[j][i];
            }
           // v.push_back(a);
        }
       // mat=v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n,vector<int>(n)); 

        for(int i=0; i<n; i++)
        {
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        ob.transpose(matrix,n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                cout<<matrix[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends