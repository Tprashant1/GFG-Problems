//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    int solve(int index,int n,vector<int>&price,vector<vector<int>>&dp){
        if(index == 0){
            return n*price[0];
        }
        
        if(dp[index][n] != -1){
            return dp[index][n];
        }
        
        int notTake = 0 + solve(index-1,n,price,dp);
        int take = INT_MIN;
        int rodLen = index+1;
        if(rodLen <= n){
            take = price[index] + solve(index,n-rodLen,price,dp);
        }
        
        return dp[index][n] = max(take,notTake);
    }
  
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(n-1,n,price,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends