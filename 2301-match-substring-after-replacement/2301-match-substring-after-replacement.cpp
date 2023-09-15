class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
       if(sub.size()>s.size()){
           return 0;
       } 
       map<char,set<char>>m;
        for(auto x:mappings){
            m[x[0]].insert(x[1]);
        }
        int n=s.size();
        int k=sub.size();
        for(int i=0;i<=n-k;i++){
            bool flag=1;
            for(int j=0;j<k;j++){
                if(s[i+j]==sub[j] || m[sub[j]].find(s[i+j])!=m[sub[j]].end()){
                    continue;
                }
                else{
                    flag=0;
                    break;
                }  
            }
            if(flag==1){
                return 1;
            }
        }
        return 0;
    }
};