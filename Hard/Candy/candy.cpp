//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minCandy(int N, vector<int> &ratings) {
        if(N==1){
            return N;
        }
        vector<int>ans(N);
        for(int i=0;i<N;i++){
            ans[i] = 1;
        }
        
        for(int i=0;i<N;i++){
            if(ratings[i] > ratings[i-1]){
                ans[i] = ans[i-1]+1;
            }
        }
        
        for(int i=N-1;i>=0;i--){
            if(ratings[i-1] > ratings[i] && ans[i-1]<=ans[i]){
                ans[i-1] = ans[i]+1;
            }
        }
        
        int res=0;
        for(int i=0;i<N;i++){
            res = res+ans[i];
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends