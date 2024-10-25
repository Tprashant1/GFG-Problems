//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    vector<int> alternateSort(vector<int>& arr) {
        vector<int>temp;
        temp = arr;
        sort(temp.begin(),temp.end());
        int n = temp.size();
        int i = 0;
        int j = n-1;
        int k = 0;
        while(k < n){
            if(k % 2 != 0){
                arr[k] = temp[i];
                i++;
                k++;
            } 
            else{
                arr[k] = temp[j];
                j--;
                k++;
            }
        }
        return arr;
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
        Solution obj;
        vector<int> ans = obj.alternateSort(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends