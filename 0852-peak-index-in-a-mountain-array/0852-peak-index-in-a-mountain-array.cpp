class Solution {
public:
    int peakIndexInMountainArray(vector<int>& v) {
        int lo=0;int hi=v.size()-1;
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(v[mid]<v[mid+1]){
                lo=mid+1;
            }
            else{
                hi=mid;
            }
        }
        return lo;
    }
};