//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int solveMem(vector<int>&weight, vector<int> &value, int index, int w,vector<vector<int>>&dp){
	if(index == 0){
		if(weight[index] <= w){
			return value[index];
		}
		else{
			return 0;
		}
	}

	if(dp[index][w] != -1){
		return dp[index][w];
	}

	int incl = 0 ;
	if(weight[index] <= w){
		incl = value[index] + solveMem(weight,value,index-1,w-weight[index],dp);
	}

	int excl = 0 + solveMem(weight,value,index-1,w,dp);

	dp[index][w] = max(incl,excl);
	return dp[index][w];
}
    
    
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n = wt.size();
        vector<vector<int>>dp(wt.size()+1,vector<int>(W+1,-1));
	    return solveMem(wt,val,n-1,W,dp);
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends