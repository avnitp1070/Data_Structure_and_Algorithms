//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& v, int n, long long k) {
         int i=0;
         long long sum=1;
         int ans=0;
         for(int j=0;j<n;j++){
             sum*=v[j];
             while(i<=j && sum>=k){
                 sum/=v[i];
                 i++;
             }
             ans+=(j-i+1);
         }
         return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends