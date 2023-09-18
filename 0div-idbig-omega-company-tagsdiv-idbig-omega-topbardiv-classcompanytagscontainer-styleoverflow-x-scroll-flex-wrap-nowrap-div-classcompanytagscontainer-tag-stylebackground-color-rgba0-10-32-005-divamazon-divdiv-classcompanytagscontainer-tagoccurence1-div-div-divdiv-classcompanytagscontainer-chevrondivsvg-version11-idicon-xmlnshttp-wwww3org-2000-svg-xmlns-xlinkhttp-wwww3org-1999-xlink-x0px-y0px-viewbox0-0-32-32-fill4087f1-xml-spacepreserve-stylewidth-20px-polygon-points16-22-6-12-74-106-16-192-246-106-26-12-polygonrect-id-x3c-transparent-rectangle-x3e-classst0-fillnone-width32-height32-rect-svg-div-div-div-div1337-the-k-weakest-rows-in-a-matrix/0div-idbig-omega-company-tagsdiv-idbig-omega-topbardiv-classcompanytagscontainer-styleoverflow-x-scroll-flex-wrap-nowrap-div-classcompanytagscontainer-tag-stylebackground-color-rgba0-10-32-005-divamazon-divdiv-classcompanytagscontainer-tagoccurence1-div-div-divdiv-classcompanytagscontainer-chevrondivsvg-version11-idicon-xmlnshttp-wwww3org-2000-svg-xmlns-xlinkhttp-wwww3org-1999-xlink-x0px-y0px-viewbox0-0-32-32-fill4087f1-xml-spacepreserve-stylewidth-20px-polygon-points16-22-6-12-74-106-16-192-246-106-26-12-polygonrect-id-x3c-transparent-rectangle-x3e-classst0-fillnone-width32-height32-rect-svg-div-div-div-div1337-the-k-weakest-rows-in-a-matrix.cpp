class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        int t=0;
        for(auto x:mat){
            int p=0;
            for(int i=0;i<x.size();i++){
                if(x[i]==1){
                    p++;
                }
                else{
                    break;
                }
            }
            pq.push({p,t});
            if(pq.size()>k){
                pq.pop();
            }
            t++;
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};