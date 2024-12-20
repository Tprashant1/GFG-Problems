//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        vector<int>ans;
        int row = mat.size();
        int col = mat[0].size();
        int count =0;
        int total = row*col;

        int startRow =0 ;
        int startCol = 0;
        int endRow = row-1;
        int endCol = col-1;
    
        while(count<total){
            for(int index = startCol;count<total && index<=endCol; index++){
                ans.push_back(mat[startRow][index]);
                count++;
            }
            startRow++;

            for(int index = startRow;count<total && index<=endRow; index++){
                ans.push_back(mat[index][endCol]);
                count++;
            }
            endCol--;

            for(int index = endCol;count<total && index>=startCol; index--){
                ans.push_back(mat[endRow][index]);
                count++;
            }
            endRow--;

            for(int index = endRow;count<total && index>=startRow; index--){
                ans.push_back(mat[index][startCol]);
                count++;
            }
            startCol++;

        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends