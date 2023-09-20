class Solution {
public:
    int subarraysDivByK(vector<int>& v, int k) {
        int n=v.size();
        map<int,int>m;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=v[i];
            int t=sum%k;
            m[((t)+k)%k]++;
        }
        int ans=0;
        for(int i=0;i<k;i++){
            if(m[i]>1){
                ans+=(m[i]*(m[i]-1))/2;
            }
        }
        ans+=m[0];
        return ans;
    }
};