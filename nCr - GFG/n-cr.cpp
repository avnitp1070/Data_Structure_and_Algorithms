//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define ll long long
class Solution{
public:
ll fac[1005];
ll mod=1e9+7;
void fact()
{
    fac[0]=1;
    for(ll i=1;i<1005;i++){
        fac[i] = fac[i-1]*i; // (a*b)%m = ((a%m)*(b%m))%m
        fac[i]%=mod;
    }
}
//---------binary exponantiation----------------
ll binExp(ll x,ll n)
{
    ll res=1;
    while(n){
        if(n%2==1){
            res*=x;
            res%=mod;
        }
        n/=2;
        x*=x;
        x%=mod;
    }
    return res;
}
//--------------ncr-------------------------------
ll ncr(int n,int r)
{
    ll temp1 = fac[n];
    ll temp2 = fac[n-r]*fac[r];
    temp2%=mod;
    ll temp3 = binExp(temp2,mod-2); // temp3 is the modulo inverse
    temp1*=temp3;
    temp1%=mod;
    return temp1;
}


int nCr(int n, int r){
        // code here
         if(r>n){
        return 0;
    }
    if(r==n){
        return 1;
    }
        fact();
        return (int)ncr(n,r);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends