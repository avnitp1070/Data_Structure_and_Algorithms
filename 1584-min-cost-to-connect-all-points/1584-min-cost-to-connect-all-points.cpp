class Solution {
public:
    vector<int>parent;
    void make_set(int n){
        parent.resize(n+5);
        for(int i=0;i<n+5;i++){
            parent[i]=i;
        }
    }
    int find(int x){
        if(x==parent[x]){
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    
    void make_union(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y){
            return;
        }
        parent[y]=x;
    }
    int minCostConnectPoints(vector<vector<int>>& x) {
        int n=x.size();
        make_set(n);
        vector<pair<int,pair<int,int>>>v;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int k=abs(x[i][0]-x[j][0])+abs(x[i][1]-x[j][1]);
                v.push_back({k,{i,j}});
            }
        }
        sort(v.begin(),v.end());
        int ans=0;
        for(auto t:v){
            int val=t.first;
            int a=t.second.first;
            int b=t.second.second;
            if(find(a)!=find(b)){
                ans+=val;
                make_union(a,b);
            }
        }
        return ans;
    }
};