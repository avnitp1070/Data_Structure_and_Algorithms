class Solution {
public:
    int countWays(vector<int>& v) {
        sort(v.begin(),v.end());
        int ans=0;
        int n=v.size() ;
        if(v[0]>0) 
            ans++;
        
        for(int i=0;i<n-1;i++){
           if(v[i]<i+1 && v[i+1]>i+1)
               ans++;
        }
        if(v.back()<n) 
            ans++;
        return ans;
    }
};