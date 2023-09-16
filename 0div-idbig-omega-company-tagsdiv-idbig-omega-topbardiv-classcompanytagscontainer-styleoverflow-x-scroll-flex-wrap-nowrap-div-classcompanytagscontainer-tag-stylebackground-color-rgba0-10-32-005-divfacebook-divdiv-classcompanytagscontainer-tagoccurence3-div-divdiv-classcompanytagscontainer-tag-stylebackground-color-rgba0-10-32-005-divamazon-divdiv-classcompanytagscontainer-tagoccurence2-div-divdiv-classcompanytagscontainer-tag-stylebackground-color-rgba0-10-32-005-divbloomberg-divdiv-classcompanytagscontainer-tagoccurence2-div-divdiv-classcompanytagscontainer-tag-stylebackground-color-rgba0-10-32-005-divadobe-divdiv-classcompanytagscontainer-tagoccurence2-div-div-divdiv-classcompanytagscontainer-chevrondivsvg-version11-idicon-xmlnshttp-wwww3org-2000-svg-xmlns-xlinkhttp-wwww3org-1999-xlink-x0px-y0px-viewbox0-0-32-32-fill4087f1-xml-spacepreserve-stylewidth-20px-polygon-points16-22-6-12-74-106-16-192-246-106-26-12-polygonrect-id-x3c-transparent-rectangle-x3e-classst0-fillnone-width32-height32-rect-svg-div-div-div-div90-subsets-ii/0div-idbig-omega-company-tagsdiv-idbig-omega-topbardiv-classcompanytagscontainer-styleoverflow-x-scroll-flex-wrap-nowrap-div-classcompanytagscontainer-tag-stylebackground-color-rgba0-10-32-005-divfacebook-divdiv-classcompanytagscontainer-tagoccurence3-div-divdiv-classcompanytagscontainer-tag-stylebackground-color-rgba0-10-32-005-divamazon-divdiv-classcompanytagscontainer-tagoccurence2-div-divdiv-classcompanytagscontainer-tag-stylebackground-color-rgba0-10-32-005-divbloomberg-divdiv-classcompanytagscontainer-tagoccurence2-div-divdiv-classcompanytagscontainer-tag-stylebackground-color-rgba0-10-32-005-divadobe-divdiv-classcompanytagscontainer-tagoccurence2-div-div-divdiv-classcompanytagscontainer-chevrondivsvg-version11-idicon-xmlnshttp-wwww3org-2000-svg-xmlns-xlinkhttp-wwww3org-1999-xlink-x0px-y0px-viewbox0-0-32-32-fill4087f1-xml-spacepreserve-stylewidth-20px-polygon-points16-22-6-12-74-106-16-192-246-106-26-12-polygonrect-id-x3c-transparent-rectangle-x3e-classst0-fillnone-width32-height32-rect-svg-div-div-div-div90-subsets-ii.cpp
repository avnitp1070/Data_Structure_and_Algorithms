class Solution {
public:
    void solve(vector<int>&p,vector<int>&n,int i,set<vector<int>>&s){
       if(i==n.size()){
           s.insert(p);
           return ;
       }
         p.push_back(n[i]);
        // sort(p.begin(),p.end());
        solve(p,n,i+1,s);
         p.pop_back();
        solve(p,n,i+1,s);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& n) {
        vector<vector<int>> v;
        vector<int>p;
        int i=0;
        set<vector<int>>s;
        sort(n.begin(),n.end());
        solve(p,n,i,s);
        for(auto it:s){
            v.push_back(it);
        }
        return v;
    }
};