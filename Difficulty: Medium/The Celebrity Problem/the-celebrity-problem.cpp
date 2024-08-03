//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    
    bool knows(vector<vector<int> >& M, int a,int b){
        if(M[a][b]==1){
            return true;
        }
        else{
            return false;
        }
    }
    
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
        stack<int>s;
        for(int i=0;i<n;i++){
            s.push(i) ;
        }
        
        while(s.size() > 1){
            int a = s.top() ;
            s.pop() ;
            int b = s.top() ;
            s.pop() ;
            if(knows(mat,a,b)){
                s.push(b) ;
            }
            else{
                s.push(a);
            }
        }
        
        int ans = s.top() ;
        
        int zeroCount = 0 ;
        for(int i=0;i<n;i++){
            if(mat[ans][i]==0){
                zeroCount++;
            }
        }
        if(zeroCount != n){
            return -1;
        }
        
        int oneCount = 0;
        for(int i=0;i<n;i++){
            if(mat[i][ans]==1){
                oneCount++;
            }
        }
        if(oneCount != n-1){
            return -1;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends