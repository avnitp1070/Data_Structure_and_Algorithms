class Solution {
public:
    void solve(vector<int>&nums,vector<int>&op,int i,int target,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(op);
            return;
        }
        if(i==nums.size() || target<0){
            return;
        }
       for(int j=i;j<nums.size();j++){
           if(j>i && nums[j]==nums[j-1]){
               continue;
           }
                op.push_back(nums[j]);
                solve(nums,op,j+1,target-nums[j],ans);
                op.pop_back();

           }
        }
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
      vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        vector<int>op;
        solve(nums,op,0,target,ans);
        return ans;  
    }
};
