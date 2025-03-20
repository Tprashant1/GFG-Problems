//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    int solve(int i, int n, int k, vector<int>&prices, vector<vector<int>>&dp){
        if(i>=n || k>=4){
            return 0;
        }
        
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        
        if(k%2==0){
            return dp[i][k]=max(-prices[i]+solve(i+1, n, k+1, prices, dp), solve(i+1, n, k, prices, dp));
        }
        else{
            return dp[i][k]=max(prices[i]+solve(i+1, n, k+1, prices, dp), solve(i+1, n, k, prices, dp));
        }
    }

    
    int maxProfit(vector<int> &prices) {
        int n=prices.size();
        vector<vector<int>>dp(n, vector<int>(4, -1));
        return solve(0, n, 0, prices, dp);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends