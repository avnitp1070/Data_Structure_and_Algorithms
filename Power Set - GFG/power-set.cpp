//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	   void solve(string ip,string op,vector<string>&v){
	        if(ip.size()==0){
	            if(op.size()>0)
	            v.push_back(op);
	            return;
	        }
	        string op1=op;
	        string op2=op;
	        op2+=(ip[0]);
	        ip.erase(ip.begin()+0);
	        solve(ip,op1,v);
	        solve(ip,op2,v);
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string>v;
		    string op;
		    solve(s,"",v);
		    sort(v.begin(),v.end());
		    return v;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends