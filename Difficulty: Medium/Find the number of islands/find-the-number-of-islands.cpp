//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    
    void DFS(int i, int j, int n, int m,vector<vector<bool>>&vis,vector<vector<char>>&grid){
        vis[i][j] = true;
        
        vector<int>newRow = {-1,-1,0,1,1,1,0,-1};
        vector<int>newCol = {0,1,1,1,0,-1,-1,-1};
        
        for(int k=0;k<8;k++){
            int x = i + newRow[k];
            int y = j + newCol[k];
            
            if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '1' && !vis[x][y]){
                DFS(x,y,n,m,vis,grid);
            }
        }
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    ans++;
                    DFS(i,j,n,m,vis,grid);
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends