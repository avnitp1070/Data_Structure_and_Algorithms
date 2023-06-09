//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

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
    int numProvinces(vector<vector<int>> v, int n) {
        //int n=v.size();
        int cnt=n;
        make_set(n);
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]){
                    if(find(i)==find(j)){
                        //cnt--;
                    }
                    else{
                        cnt--;
                    }
                    union_set(i,j);
                }
            }
        }
        // vector<int>vis(n+1,0);
        // for(int i=0;i<n;i++){
        //     if(vis[i]==0){
        //         cnt++;
        //         dfs(i,vis,adj);
        //     }
        // }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends