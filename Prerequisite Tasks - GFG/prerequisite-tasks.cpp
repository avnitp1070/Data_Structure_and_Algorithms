//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int n, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int>adj[n];
	    for(auto x:prerequisites){
	        adj[x.first].push_back(x.second);
	    }
	    vector<int>in(n,0);
	    for(int i=0;i<n;i++){
	        for(auto x:adj[i]){
	            in[x]++;
	        }
	    }
	    queue<int>q;
	    int cnt=0;
	    for(int i=0;i<n;i++){
	        if(in[i]==0){
	            q.push(i);
	        }
	    }
	    while(!q.empty()){
	        int x=q.front();q.pop();
	        cnt++;
	        for(auto child:adj[x]){
	            in[child]--;
	            if(in[child]==0){
	                q.push(child);
	            }
	        }
	        
	        
	    }
	    return cnt<n?0:1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends