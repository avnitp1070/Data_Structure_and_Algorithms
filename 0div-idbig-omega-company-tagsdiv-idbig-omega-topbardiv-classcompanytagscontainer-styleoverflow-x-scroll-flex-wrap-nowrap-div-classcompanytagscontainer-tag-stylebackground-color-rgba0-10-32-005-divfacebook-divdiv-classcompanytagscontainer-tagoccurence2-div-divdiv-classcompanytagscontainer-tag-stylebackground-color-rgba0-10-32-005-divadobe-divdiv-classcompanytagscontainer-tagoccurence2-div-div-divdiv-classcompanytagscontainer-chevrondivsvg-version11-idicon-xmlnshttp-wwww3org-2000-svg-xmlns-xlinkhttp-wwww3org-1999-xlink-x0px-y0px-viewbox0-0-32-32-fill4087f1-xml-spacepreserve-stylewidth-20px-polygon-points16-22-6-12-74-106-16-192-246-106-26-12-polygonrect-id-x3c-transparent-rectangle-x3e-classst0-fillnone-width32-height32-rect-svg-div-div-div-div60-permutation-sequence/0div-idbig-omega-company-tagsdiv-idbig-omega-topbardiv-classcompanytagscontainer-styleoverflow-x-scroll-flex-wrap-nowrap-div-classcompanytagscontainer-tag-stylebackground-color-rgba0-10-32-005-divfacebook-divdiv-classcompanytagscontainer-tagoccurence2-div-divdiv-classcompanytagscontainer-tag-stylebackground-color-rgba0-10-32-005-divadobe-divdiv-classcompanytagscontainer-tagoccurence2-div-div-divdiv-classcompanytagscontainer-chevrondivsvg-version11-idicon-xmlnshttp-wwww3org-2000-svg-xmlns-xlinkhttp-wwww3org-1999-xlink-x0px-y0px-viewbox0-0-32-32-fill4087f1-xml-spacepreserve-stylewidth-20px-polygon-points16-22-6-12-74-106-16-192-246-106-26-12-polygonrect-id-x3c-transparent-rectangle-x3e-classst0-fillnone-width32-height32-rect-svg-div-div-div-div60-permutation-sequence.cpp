class Solution {
public:
    string getPermutation(int n, int k) {
        string v;
        int fact=1;
        for(int i=1;i<=n;i++){
            fact=fact*i;
            char c=i+'0';
            v+=c;
        }
        fact/=n;
        k--;
        string ans;
        while(true){
           ans+=(v[k/fact]); 
            v.erase(v.begin()+k/fact);
           if(v.size()==0){
               break;
           }
           k=k%fact;
           fact=fact/v.size();
        }
        return ans;
    }
};