//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string sw, string tw, vector<string>& wordList) {
        // Code here
        map<string,int>m;
        for(auto x:wordList){
            m[x]=1e9;
        }
        m[sw]=1;
        queue<string>q;
        q.push(sw);
        int k=sw.size();
        while(!q.empty()){
            auto x=q.front();q.pop();
            for(int i=0;i<k;i++){
                //if(x[i]!=tw[i]){
                   string y=x;
                   for(int j=0;j<26;j++){
                       char ch=j+'a';
                        y[i]=ch;
                   if(m.find(y)!=m.end()){
                      if(m[y]>m[x]+1){
                       m[y]=m[x]+1;
                       q.push(y);
                   }  
                   }
                  // }
                   
                }
            }
        }
        return m[tw]!=1e9?m[tw]:0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends