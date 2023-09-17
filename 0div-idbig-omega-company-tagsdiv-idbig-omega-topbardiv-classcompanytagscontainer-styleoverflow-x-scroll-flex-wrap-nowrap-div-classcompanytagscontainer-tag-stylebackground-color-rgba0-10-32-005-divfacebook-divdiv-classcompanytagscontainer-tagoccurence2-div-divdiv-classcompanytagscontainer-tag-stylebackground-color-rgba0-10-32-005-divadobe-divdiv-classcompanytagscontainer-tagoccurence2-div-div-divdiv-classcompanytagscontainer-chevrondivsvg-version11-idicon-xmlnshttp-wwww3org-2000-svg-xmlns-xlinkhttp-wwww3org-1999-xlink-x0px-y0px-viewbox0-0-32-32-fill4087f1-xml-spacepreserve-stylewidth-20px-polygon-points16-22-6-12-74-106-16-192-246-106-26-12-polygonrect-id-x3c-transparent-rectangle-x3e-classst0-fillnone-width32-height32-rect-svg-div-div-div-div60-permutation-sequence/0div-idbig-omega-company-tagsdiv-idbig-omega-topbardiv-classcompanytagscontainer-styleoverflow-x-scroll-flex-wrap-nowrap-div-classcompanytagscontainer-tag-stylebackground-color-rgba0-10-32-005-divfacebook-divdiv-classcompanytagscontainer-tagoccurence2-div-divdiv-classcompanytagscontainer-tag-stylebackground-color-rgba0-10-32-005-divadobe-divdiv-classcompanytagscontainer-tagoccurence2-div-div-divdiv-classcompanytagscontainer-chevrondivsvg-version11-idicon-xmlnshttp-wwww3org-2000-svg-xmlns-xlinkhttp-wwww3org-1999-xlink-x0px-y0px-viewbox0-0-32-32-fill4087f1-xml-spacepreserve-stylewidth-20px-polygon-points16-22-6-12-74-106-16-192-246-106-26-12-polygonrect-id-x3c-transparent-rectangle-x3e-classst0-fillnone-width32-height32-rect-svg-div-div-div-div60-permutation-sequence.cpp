class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }
        for(int i=0;i<k-1;i++){
            next_permutation(v.begin(),v.end());
        }
        string s;
        for(int i=0;i<n;i++){
            char a=v[i]+'0';
            s+=a;
        }
        return s;
    }
};