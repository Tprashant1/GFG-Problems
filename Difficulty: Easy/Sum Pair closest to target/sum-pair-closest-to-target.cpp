//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        vector<int>ans;
        int n = arr.size();
        int diff = INT_MAX;
        int s = 0;
        int e = n-1;
        while(s < e){
            int pairSum = arr[s]+arr[e];
            if(abs(pairSum-target) < diff){
                diff = min(abs(pairSum-target),diff);
                ans = {arr[s],arr[e]};
            }
            if(pairSum < target){
                s++;
            }
            else if(pairSum > target){
                e--;
            }
            else if(pairSum == target){
                return ans;
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends