class Solution {
public:
    vector<vector<int>>res;
    void solve(vector<int>&cur,vector<int>&freq,vector<int>&v){
        if(cur.size()==v.size()){
            res.push_back(cur);
            return;
        }
        for(int i=0;i<v.size();i++){
            if(freq[i]==0){
                freq[i]=1;
                cur.push_back(v[i]);
                solve(cur,freq,v);
                freq[i]=0;
                cur.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>freq(nums.size(),0);
        vector<int>cur;
        solve(cur,freq,nums);
        return res;
    }
};