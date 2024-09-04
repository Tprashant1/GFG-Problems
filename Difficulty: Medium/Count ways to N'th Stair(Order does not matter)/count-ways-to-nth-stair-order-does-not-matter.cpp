//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    
	    int solve(int n,vector<int>&dp){
	        if(n == 0 || n == 1){
	            return 1;
	        }
	        
	        if(dp[n] != -1){
	            return dp[n];
	        } 
	        
	        int ans = 1 + min(solve(n-1,dp),solve(n-2,dp));
	        dp[n] = ans;
	        return ans;
	    }
	    
		int nthStair(int n){
		    vector<int>dp(n+1,-1);
		    return solve(n,dp);
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthStair(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends