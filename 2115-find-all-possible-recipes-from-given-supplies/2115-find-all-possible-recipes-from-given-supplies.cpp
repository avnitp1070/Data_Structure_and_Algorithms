class Solution {
public:
    vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ing, vector<string>& sup) {
        unordered_map<string,int>m;
        for(auto x:sup){
            m[x]++;
        }
         unordered_set<string>ans;
        int t=100;
        while(t--){
            for(int i=0;i<rec.size();i++){
                if(ans.find(rec[i])!=ans.end()){
                    continue;
                }
            int k=1;
            for(int j=0;j<ing[i].size();j++){
                if(m.find(ing[i][j])!=m.end()){
                   
                }
                else{
                    k=0;
                    break;
                }
            }
            if(k==1){
                ans.insert(rec[i]);
                m[rec[i]]++;
            }
           }
            if(ans.size()==rec.size()){
                break;
            }
        }
        vector<string>res;
        for(auto x:ans){
            res.push_back(x);
        }
        return res;
    }
};