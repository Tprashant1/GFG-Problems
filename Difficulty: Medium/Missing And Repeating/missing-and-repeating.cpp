//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        vector<int>ans(2);
        int n = arr.size();
        unordered_map<int,int>mp;
        for(auto i:arr){
            mp[i]++;
        }
        for(int i=1;i<=n;i++){
            if(mp.find(i) == mp.end()){
                ans[1] = i;
                break;
            }
        }
        
        for(auto i:mp){
            if(i.second > 1){
                ans[0] = i.first;
                break;
            }
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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends