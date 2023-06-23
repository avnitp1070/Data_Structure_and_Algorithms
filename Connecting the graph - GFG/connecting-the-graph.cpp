//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int>parent;
    void make_set(int n){
      parent.resize(n+5); 
      for(int i=0;i<n+5;i++){
          parent[i]=i;
       }
     }
    int find(int x){
       if( parent[x] == x) {
            return x;
        }
       return parent[x]=find(parent[x]);
    }

    bool union_set(int x,int y){
        int p=find(x);
        int q=find(y);
        if(p==q){
            return true;
        }
        parent[p]=q;
        return false;
    }
    
    
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        make_set(n);
        int req=n-1;
        int avl=0;
        for(auto x:edge){
            int a=x[0];
            int b=x[1];
            if(find(a)==find(b)){
                avl++;
                continue;
            }
            req--;
            union_set(a,b);
        }
        if(avl>=req){
            return req;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends