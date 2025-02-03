//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int n;
    int m;
    
    
    bool DFS(vector<vector<char>>&mat,int i,int j,int index,string& word,vector<vector<bool>>&visited){
        
        if(index == word.size()){
            return true;
        }
        
        if(i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || mat[i][j] != word[index]){
            return false;
        }
        
        visited[i][j] = true;
        if(DFS(mat,i+1,j,index+1,word,visited) || DFS(mat,i-1,j,index+1,word,visited) || DFS(mat,i,j-1,index+1,word,visited) || DFS(mat,i,j+1,index+1,word,visited)){
            return true;
        }
        visited[i][j] = false;
        return false;
    }
    
    
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        n = mat.size();
        m = mat[0].size();
        
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(mat[i][j]==word[0]){
                  vector<vector<bool>> visit(n, vector<bool>(m, false));
                  if(DFS(mat,i,j,0,word, visit)){
                      return true;
                  }
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends