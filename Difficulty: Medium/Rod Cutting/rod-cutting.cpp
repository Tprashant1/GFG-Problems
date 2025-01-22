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
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        // return solve(n-1,n,price,dp);
        
        
        for(int i=0; i<=n; i++){
            dp[0][i]=i*price[0];
        }
        
        for(int i=1; i<n; i++){
            for(int j=0; j<=n; j++){
                int notTake=dp[i-1][j];
                int take=-1;
                if(i+1 <= j){
                    take=price[i]+dp[i][j-i-1];
                }
                dp[i][j]=max(take,notTake);
            }
        }
        
        return dp[n-1][n];
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