//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string str1, string str2) 
	{ 
	    int m = str1.size();
	    int n = str2.size();
	    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
	    for(int i=1;i<m+1;i++){
	        for(int j=1;j<n+1;j++){
	            if(str1[i-1] == str2[j-1]){
	                dp[i][j] = 1 + dp[i-1][j-1];
	            }
	            else{
	                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
	            }
	        }
	    }
	    
	    int ans = dp[m][n];
	    int c1 = m - ans;
	    int c2 = n - ans;
	    
	    return c1 + c2;
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends