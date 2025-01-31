//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isSafe(int row,int col,vector<vector<int>>& board,int val){
        for(int i=0;i<board.size();i++){
            if(board[row][i] == val){
                return false;
            }
            if(board[i][col] == val){
                return false;
            }
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == val){
                return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<int>>& board){
        int n = board[0].size();
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(board[row][col] == 0){
                    for(int val=1;val<=9;val++){
                        if(isSafe(row,col,board,val)){
                            board[row][col] = val;
                            bool nextposiblesolution = solve(board);
                            if(nextposiblesolution){
                                return true;
                            }
                            else{
                                board[row][col] = 0;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
      
    // Function to find a solved Sudoku.
    void solveSudoku(vector<vector<int>> &mat) {
        solve(mat);
    }
};

//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends