//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    int solve(vector<int>&coins,int sum,int index,vector<vector<int>>&dp){
        if(sum == 0){
            return 1;
        }
        
        if(index < 0 || sum < 0){
            return 0;
        }
        
        if(dp[index][sum] != -1){
            return dp[index][sum];
        }
        
        int notTake = solve(coins,sum,index-1,dp);
        int take = 0;
        if(coins[index] <= sum){
            take = solve(coins,sum-coins[index],index,dp);
        }
        
        return dp[index][sum] = (take + notTake);
    }
  
    int count(vector<int>& coins, int sum) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(coins,sum,n-1,dp);
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends