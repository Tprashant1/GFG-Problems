//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    void sequence(int N,vector<int>&ans){
        ans.push_back(N) ;
        if(N<=0){
            return;
        }
        sequence(N-5,ans);
        ans.push_back(N) ;
    }
public:
    vector<int> pattern(int N){
        vector<int>ans;
        sequence(N,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends