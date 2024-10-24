//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
        int count = 0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            while(arr[i] != i+1){
                swap(arr[i],arr[arr[i]-1]);
                count++;
                
                if(count>2){
                    return false;
                }

            }
        }
        if(count == 0 || count == 2){
            return true;
        }
        else{
            return false;
        }
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends