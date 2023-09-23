class Solution {
public:
    int solve(string &s,map<string,int>&m,map<string,int>&dp){
        if(s.size()==0){
            return 0;
        }
        if(dp.find(s)!=dp.end()){
            return dp[s];
        }
        int ans=1;
        for(int i=0;i<s .size();i++){
            string p=s;
            p.erase(p.begin()+i);
            if(m.find(p)!=m.end()){
                ans=max(ans,1+solve(p,m,dp));
            }
        }
        return dp[s]=ans;
    }
    int longestStrChain(vector<string>& words) {
        map<string,int>m;
        for(auto x:words){
            m[x]++;
        }
        map<string,int>dp;
        int ans=0;
        for(auto x:words){
            ans=max(ans,solve(x,m,dp));
        }
        return ans;
    }
};