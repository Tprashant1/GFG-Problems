//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    int solve(int index,int k,vector<int>&arr,vector<int>&dp){
        if(index == arr.size()-1){
            return 0;
        }
        
        if(dp[index] != -1){
            return dp[index];
        }
        
        int mini = INT_MAX;
    
        for(int i=1;i<=k;i++){
            if(index+i < arr.size()){
                int cost = abs(arr[index] - arr[index+i]) + solve(index+i,k,arr,dp);
                mini = min(mini,cost);
            }
        }
        
        return dp[index] = mini;
        
    }
    
    
    int solveTab(int k,vector<int>&arr){
        int n = arr.size();
        vector<int>dp(n+1,INT_MAX);
        dp[n-1] = 0 ;

        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<=i+k && j<=n-1;j++){
                dp[i] = min(dp[i],abs(arr[i] -arr[j]) + dp[j]);
            }
        }
        return dp[0];
    }
    
    int minimizeCost(int k, vector<int>& arr) {
        // int n = arr.size();
        // vector<int>dp(n+1,-1);
        return solveTab(k,arr);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends