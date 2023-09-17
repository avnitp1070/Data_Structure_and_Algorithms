class Solution {
public:
    vector<vector<int>>res;
    void solve(int ind,vector<int>&v){
        if(ind==v.size()){
            res.push_back(v);
            return;
        }
        for(int i=ind;i<v.size();i++){
            swap(v[i],v[ind]);
            solve(ind+1, v);
            swap(v[i],v[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        solve(0,nums);
        return res;
    }
};