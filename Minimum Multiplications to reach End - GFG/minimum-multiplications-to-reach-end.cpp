//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        vector<int>dist(1e5,1e9);
        queue<pair<int,int>>q;
        q.push({0,start});
        dist[start]=0;
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int x=p.second;
            int steps=p.first;
            for(auto it:arr){
                int xx=(x*it)%100000;
                if(xx==end){
                    return steps+1;
                }
                if(dist[xx]>steps+1){
                    dist[xx]=steps+1;
                    q.push({steps+1,xx});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends