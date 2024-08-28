//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    static  bool compare(pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second > b.second; 
    }
    
    vector<int> sortByFreq(vector<int>& arr) {
        unordered_map<int, int> mp;

        for (int num : arr) {
            mp[num]++;
        }

        vector<pair<int, int>>ans;
        for (auto& it : mp) {
            ans.push_back(it);
        }

        sort(ans.begin(),ans.end(),compare);

        vector<int> result;
        for (auto& it : ans) {
            int count = it.second;
            while (count--) {
                result.push_back(it.first);
            }
        }

        return result;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends