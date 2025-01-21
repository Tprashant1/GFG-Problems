//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int dp[1002][1002] ;
  
    int solve(vector<int> &wt, vector<int> &val,int n,int w){
        if(n == 0 || w == 0){
            return 0;
        }
        
        if(dp[n][w] != -1){
            return dp[n][w];
        }
        
        if(wt[n-1] <= w){
            return dp[n][w] =max(val[n-1] + solve(wt,val,n-1,w-wt[n-1]), solve(wt,val,n-1,w));
        }
        
        else{
            return dp[n][w] = solve(wt,val,n-1,w);
        }
    }
  
    // Function to return max value that can be put in knapsack of capacity.
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
        memset(dp,-1,sizeof(dp));
        return solve(wt,val,n,capacity);
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
        cout << solution.knapSack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends