//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        vector<int>arr;
        int temp = nums.size()/3;
        for(auto i:mp){
            if(i.second > temp){
                arr.push_back(i.first);
            }
        }
        
        if(arr.size() == 0){
            return {-1};
        }
        return arr;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends