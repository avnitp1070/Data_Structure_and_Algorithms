class Solution {
public:
    void solve(int i,vector<int>&v,vector<int>&op,set<vector<int>>&s){
        if(i==v.size()){
            s.insert(op);
            return;
        }
        op.push_back(v[i]);
        solve(i+1,v,op,s);
        op.pop_back();
        solve(i+1,v,op,s);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& v) {
         vector<vector<int>>ans;
         set<vector<int>>s;
        vector<int>op;
        sort(v.begin(),v.end());
         solve(0,v,op,s);
        for(auto x:s){
            ans.push_back(x);
        }
        return ans;
    }
};