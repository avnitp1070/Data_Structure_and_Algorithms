//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        double v[n];
        vector<pair<double,double>>t;
        for(int i=0;i<n;i++){
            double a=arr[i].value;
            double b=arr[i].weight;
            if(b>0)
             v[i]=a/b;
            else
              v[i]=0;
            t.push_back({v[i],b});
        }
        double w=W;
    double ans=0;
    sort(t.begin(),t.end());
    reverse(t.begin(),t.end());
    for(int i=0;i<n;i++){
        if(w>=t[i].second){
            ans+=t[i].second*t[i].first;
            w-=t[i].second;
        }
        else{
            ans+=w*t[i].first;
            w=0;
        }
    }
    return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends