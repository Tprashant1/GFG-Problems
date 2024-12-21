//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>grid(n,vector<int>(m));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j] = mat[i][j];
            }
        }
        
        for(vector<int>&row:grid){
            reverse(row.begin(),row.end());
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mat[i][j] = grid[j][i];
            }
        }
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(n, 0);
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << matrix[i][j] << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends