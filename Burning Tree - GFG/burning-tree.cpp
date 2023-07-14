//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void makeParent(Node* root,map<Node*,Node*>&m){
        queue<Node*>q;
        q.push(root);
        m[root]=NULL;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            
            if(node->left){
                m[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                m[node->right]=node;
                q.push(node->right);
            }
        }
    }
    
    void findTargetNode(Node* root,int target,Node* &tar){
        if(root==NULL){
            return;
        }
        if(root->data==target){
            tar=root;
        }
        findTargetNode(root->left,target,tar);
        findTargetNode(root->right,target,tar);
        //return NULL;
    }
    int minTime(Node* root, int tar) 
    {
       map<Node*,Node*>m;
       makeParent(root,m);
       
       Node* target;
       findTargetNode(root,tar,target);
       //check for node in all directions left,right and upward
       long long ans=0,t=0;
       queue<pair<Node*,long long>>q;
       q.push({target,t});
       map<Node*,int>vis;
       vis[target]=1;
       while(!q.empty()){
           auto p=q.front();
           q.pop();
           long long k=p.second;
           auto node=p.first;
           ans=max(ans,k);
           if(node->left && vis.count(node->left)==0){
               q.push({node->left,k+1});
               vis[node->left]=1;
           }
           
           if(node->right && vis.count(node->right)==0){
               q.push({node->right,k+1});
               vis[node->right]=1;
           }
           
           if(m[node]!=NULL && vis.count(m[node])==0){
               q.push({m[node],k+1});
               vis[m[node]]=1;
           }
       }
       return (int)ans;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends