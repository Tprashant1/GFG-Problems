//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int m = Matrix.size();
        int n = Matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[0][i] = Matrix[0][i];
        }

        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                int up = Matrix[i][j] + dp[i-1][j];

                int ld = INT_MIN;
                if(j-1 >= 0){
                    ld = Matrix[i][j] + dp[i-1][j-1];
                }

                int rd = INT_MIN;
                if(j+1 < m){
                    rd = Matrix[i][j] + dp[i-1][j+1];
                }
                dp[i][j] = max(up,max(ld,rd));
            }
        }

        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            ans = max(ans,dp[m-1][i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends