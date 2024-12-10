//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        sort(intervals.begin(),intervals.end());
        int count = 0;
        int n = intervals.size();
        int prevEnd = intervals[0][1];
        for(int i=1;i<n;i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            
            if(intervals[i][0] == intervals[i-1][0]){
                count++;
            }
            else{
                if(start >= prevEnd){
                    prevEnd = end;
                }
                else{
                    prevEnd = min(prevEnd,intervals[i][1]);
                    count++;
                }
            }
        }
        
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(intervals) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends