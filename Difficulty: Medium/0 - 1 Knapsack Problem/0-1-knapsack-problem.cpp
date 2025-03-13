//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    int solve(int w,vector<int>&val,vector<int>&wt,int n,vector<vector<int>>&dp){
        if(n == 0){
            if(wt[0] <= w){
                return val[0];
            }
            else{
                return 0;
            }
        }
        
        if(dp[n][w] != -1){
            return dp[n][w];
        }
        
        int take = INT_MIN;
        if(wt[n] <= w){
            take = val[n] + solve(w-wt[n],val,wt,n-1,dp);
        }
        
        int notTake = 0 + solve(w,val,wt,n-1,dp);
        
        return dp[n][w] = max(take,notTake);
        
    }
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        return solve(W,val,wt,n-1,dp);
    }
};


//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends