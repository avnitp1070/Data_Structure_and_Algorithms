class Solution {
public:
    bool check(string p){
        int n=p.size();
        if(n==1){
            return 1;
        }
        for(int i=0;i<n/2;i++){
            if(p[i]!=p[n-1-i]){
                return 0;
            }
        }
        return 1;
    }
    void solve(int i,string &s,vector<string> &op,set<vector<string>>&st ){
        if(i==s.size()){
           st.insert(op);
           return;
        }
        for(int j=i;j<s.size();j++){
            if(check(s.substr(i,j-i+1))){
                op.push_back(s.substr(i,j-i+1));
                solve(j+1,s,op,st);
                op.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        set<vector<string>>st;
        vector<string>op;
        solve(0,s,op,st);
        for(auto x:st){
            ans.push_back(x);
        }
        return ans;
    }
};