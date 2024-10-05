//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    
    int solve(int n,int a[],int curr,int prev){
        if(curr == n){
            return 0;
        }
        
        //include
        int take = 0;
        if(prev == -1 || a[curr] > a[prev]){
            take = 1 + solve(n,a,curr+1,curr);
        }
        
        //exclude
        int notTake = 0 + solve(n,a,curr+1,prev);
        
        return max(take,notTake);
    }
    
    int solveMem(int n,int a[],int curr,int prev,vector<vector<int>>&dp){
        if(curr == n){
            return 0;
        }
        
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }
        
        //include
        int take = 0;
        if(prev == -1 || a[curr] > a[prev]){
            take = 1 + solveMem(n,a,curr+1,curr,dp);
        }
        
        //exclude
        int notTake = 0 + solveMem(n,a,curr+1,prev,dp);
        
        int ans = max(take,notTake);
        dp[curr][prev+1] = ans;
        return dp[curr][prev+1];
    }
    
    int solveTab(int n,int a[]){
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                //include
                int take = 0;
                if(prev == -1 || a[curr] > a[prev]){
                    take = 1 + dp[curr+1][curr+1];
                }
        
                //exclude
                int notTake = 0 + dp[curr+1][prev+1];
        
                dp[curr][prev+1] = max(take,notTake);
            }
        }
        return dp[0][0];
    }
    
    
    int solveSpace(int n,int a[]){
        vector<int>currRow(n+1,0);
        vector<int>nextRow(n+1,0);
        
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                //include
                int take = 0;
                if(prev == -1 || a[curr] > a[prev]){
                    take = 1 + nextRow[curr+1];
                }
        
                //exclude
                int notTake = 0 + nextRow[prev+1];
        
                currRow[prev+1] = max(take,notTake);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }
    
    // DP with Binary Search Logic T.C = O(n*logn) , SC = O(n)
    int solveOptimal(int n,int a[]){
        if(n == 0){
            return 0;
        }
        
        vector<int>arr;
        arr.push_back(a[0]);
        
        for(int i=1;i<n;i++){
            if(a[i] > arr.back()){
                arr.push_back(a[i]);
            }
            else{
                int index = lower_bound(arr.begin(),arr.end(),a[i]) - arr.begin();
                arr[index] = a[i];
            }
        }
        return arr.size();
    }
    
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        //return solve(n,a,0,-1);
        
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return solveMem(n,a,0,-1,dp);
        
        // return solveTab(n,a);
        
        // return solveSpace(n,a);
        
        return solveOptimal(n,a);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends