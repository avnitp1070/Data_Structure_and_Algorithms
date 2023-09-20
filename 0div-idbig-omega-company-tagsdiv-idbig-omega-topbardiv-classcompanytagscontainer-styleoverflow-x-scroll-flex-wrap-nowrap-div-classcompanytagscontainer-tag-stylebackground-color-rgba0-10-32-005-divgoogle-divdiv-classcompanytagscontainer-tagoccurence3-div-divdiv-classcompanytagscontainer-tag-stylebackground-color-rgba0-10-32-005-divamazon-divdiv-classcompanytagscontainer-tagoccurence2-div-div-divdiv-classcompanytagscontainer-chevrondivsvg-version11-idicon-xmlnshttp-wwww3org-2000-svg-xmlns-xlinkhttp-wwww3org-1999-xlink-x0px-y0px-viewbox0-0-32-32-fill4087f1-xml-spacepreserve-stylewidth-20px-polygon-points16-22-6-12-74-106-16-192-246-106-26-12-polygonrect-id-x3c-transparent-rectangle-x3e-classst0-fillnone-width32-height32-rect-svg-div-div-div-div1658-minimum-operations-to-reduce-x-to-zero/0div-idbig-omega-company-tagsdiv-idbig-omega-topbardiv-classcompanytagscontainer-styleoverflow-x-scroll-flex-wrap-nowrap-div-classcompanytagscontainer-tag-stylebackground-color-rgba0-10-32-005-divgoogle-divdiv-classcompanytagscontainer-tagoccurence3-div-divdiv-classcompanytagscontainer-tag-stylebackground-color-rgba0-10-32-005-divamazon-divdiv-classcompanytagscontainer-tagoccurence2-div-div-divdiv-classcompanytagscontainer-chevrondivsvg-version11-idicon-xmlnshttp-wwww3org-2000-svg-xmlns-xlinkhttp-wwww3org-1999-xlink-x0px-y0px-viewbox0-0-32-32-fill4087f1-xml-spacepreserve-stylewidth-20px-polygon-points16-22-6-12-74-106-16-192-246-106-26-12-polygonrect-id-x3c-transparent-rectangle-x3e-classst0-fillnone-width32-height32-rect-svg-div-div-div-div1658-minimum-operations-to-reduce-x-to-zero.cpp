class Solution {
public:
    int minOperations(vector<int>& v, int x) {
        int sm=0,sum=0;
        for(auto x:v){
            sm+=x;
        }
        int target=sm-x;
        int i=0;
        int n=v.size();
        int ans=-1e9;
        for(int j=0;j<n;j++){
            sum+=v[j];
            if(i<=j && sum==target){
                ans=max(ans,j-i+1);
                sum-=v[i];
                i++;
            }
            else if(sum>target){
                while(i<=j && sum>target){
                    sum-=v[i];
                    i++;
                }
              if(i<=j && sum==target){
                ans=max(ans,j-i+1);
                sum-=v[i];
               //if(i<n-1)
                 i++;
               }
            }
        }
        if(sm==x){
            return n;
        }
        cout<<sm<<endl;
        if(ans==-1e9){
            return -1;
        }
        return n-ans;
    }
};