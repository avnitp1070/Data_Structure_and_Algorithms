class Solution {
public:
    vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ing, vector<string>& sup) {
        unordered_map<string,vector<string>>m;
        unordered_set<string>s;
        unordered_map<string,int>in;
        for(int i=0;i<rec.size();i++){
            in[rec[i]]=0;
        }
        for(auto x:sup){
            s.insert(x);
        }
        for(int i=0;i<rec.size();i++){
             for(int j=0;j<ing[i].size();j++){
                 if(s.find(ing[i][j])==s.end()){
                     m[ing[i][j]].push_back(rec[i]);
                     in[rec[i]]++;
                 }
             }
        }
         queue<string> q;
        for(auto x : in){
            if(x.second == 0){
                q.push(x.first);
            }
        }
       vector<string> ans;
        while(!q.empty()){
            string tmp = q.front();
            q.pop();
            ans.push_back(tmp);
            for(auto nbr : m[tmp]){
                in[nbr]--;
                if(in[nbr] == 0)
                    q.push(nbr);
            }
        }
        return ans;
    }
};