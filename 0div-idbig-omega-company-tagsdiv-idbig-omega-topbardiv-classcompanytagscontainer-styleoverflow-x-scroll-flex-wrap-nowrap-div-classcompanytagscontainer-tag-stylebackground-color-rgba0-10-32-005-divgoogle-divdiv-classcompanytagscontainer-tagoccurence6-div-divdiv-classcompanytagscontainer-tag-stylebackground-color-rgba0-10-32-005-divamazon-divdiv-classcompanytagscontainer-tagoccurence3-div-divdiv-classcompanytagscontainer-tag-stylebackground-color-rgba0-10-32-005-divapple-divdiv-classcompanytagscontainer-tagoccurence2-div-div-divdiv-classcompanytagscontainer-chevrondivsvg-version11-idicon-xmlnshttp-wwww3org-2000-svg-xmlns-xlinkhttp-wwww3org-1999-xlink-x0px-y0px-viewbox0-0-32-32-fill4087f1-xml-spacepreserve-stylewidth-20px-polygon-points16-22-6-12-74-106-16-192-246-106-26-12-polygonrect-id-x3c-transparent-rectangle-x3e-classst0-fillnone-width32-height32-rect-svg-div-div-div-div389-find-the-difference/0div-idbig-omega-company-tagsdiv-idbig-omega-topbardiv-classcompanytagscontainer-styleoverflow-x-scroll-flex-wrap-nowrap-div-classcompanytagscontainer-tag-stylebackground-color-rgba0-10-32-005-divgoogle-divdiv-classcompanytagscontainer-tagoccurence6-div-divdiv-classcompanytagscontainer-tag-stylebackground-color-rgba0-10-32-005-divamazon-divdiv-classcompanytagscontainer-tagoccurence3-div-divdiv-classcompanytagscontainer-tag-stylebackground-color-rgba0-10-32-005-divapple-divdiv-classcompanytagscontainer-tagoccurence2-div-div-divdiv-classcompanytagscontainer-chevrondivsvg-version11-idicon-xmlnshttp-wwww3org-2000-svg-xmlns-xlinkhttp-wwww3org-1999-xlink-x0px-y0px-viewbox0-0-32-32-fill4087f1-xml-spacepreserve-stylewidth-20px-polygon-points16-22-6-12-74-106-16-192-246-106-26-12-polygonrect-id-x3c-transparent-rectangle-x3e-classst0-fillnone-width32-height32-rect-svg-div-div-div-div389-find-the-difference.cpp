class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int>m;
        for(auto x:t){
            m[x]++;
        }
        for(auto x:s){
            m[x]--;
            if(m[x]==0){
                m.erase(x);
            }
        }
        return m.begin()->first;
    }
};