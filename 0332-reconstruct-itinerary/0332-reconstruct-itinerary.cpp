class Solution {
public:
   void dfs(string x,map<string, vector<string>>& m,vector<string>& ans){
        while(!m[x].empty()){
            string next = m[x].back();
            m[x].pop_back();
            dfs(next,m,ans);
        }
        ans.push_back(x);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string,vector<string>>m;
        for(auto x:tickets){
            m[x[0]].push_back(x[1]);
        }
        for(auto &x:m){
          sort(x.second.rbegin(),x.second.rend());   
        }
        vector<string> ans;
        
        dfs("JFK",m,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};