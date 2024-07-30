//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  private:
    void dfs(int i,int j,vector<vector<int>> &mat,int row[],int col[],vector<string> &ans,string temp,int n)
    {
        
        if(i==n-1&&j==n-1)
        {
            ans.push_back(temp);
            return;
        }
        mat[i][j]=0;
        string s="URDL";
        for(int k=0;k<4;k++)
        {
            int nrw=i+row[k];
            int ncl=j+col[k];
            if(nrw>=0&&nrw<n&&ncl>=0&&ncl<n&&mat[nrw][ncl]==1)
            {
                temp.push_back(s[k]);
                dfs(nrw,ncl,mat,row,col,ans,temp,n);
                temp.pop_back();
                
            }
            
        }
   
        mat[i][j]=1;
    }
  
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        if(mat[0][0]==0)
        {
            vector<string> ans={"-1"};
            return ans;
        }
        
        int n=mat.size();
  
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        vector<string> ans;
        string temp="";
        dfs(0,0,mat,row,col,ans,temp,n);
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
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends