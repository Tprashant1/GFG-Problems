//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    bool solveMe(int index,int N,int arr[],int target,vector<vector<int>> &dp){
        if(index>=N){
            return 0;
        }
        if(target<0){
            return 0;
        }
        if(target==0){
            return 1;
        }
        if(dp[index][target] != -1){
            return dp[index][target] ;
        }
        bool inx = solveMe(index+1,N,arr,target-arr[index],dp);
        bool ex = solveMe(index+1,N,arr,target-0,dp);
        return dp[index][target] = inx or ex;
    }
    
    
    int equalPartition(int N, int arr[])
    {
        // code here
        int total=0;
        for(int i=0;i<N;i++){
            total += arr[i];
        }
        if(total&1){
            return 0;
        }
        int target = total/2;
        
        vector<vector<int>> dp(N,vector<int>(target+1,-1));
        return solveMe(0,N,arr,target,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends