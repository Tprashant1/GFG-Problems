//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        int n = arr.size();
        vector<int>positive;
        vector<int>negative;
        
        for(auto i:arr){
            if(i >= 0){
                positive.push_back(i);
            }
            else{
                negative.push_back(i);
            }
        }
        
        int s = 0 ;
        int e = 0 ;
        int k = 0 ;
        while(k < n && s < positive.size() && e < negative.size()){
            if(k % 2 == 0){
                arr[k] = positive[s];
                s++;
                k++;
            }
            else{
                arr[k] = negative[e];
                e++;
                k++;
            }
        }
        
        while(k < n && s < positive.size()){
            arr[k] = positive[s];
            k++;
            s++;
        }
        
        while(k < n && e < negative.size()){
            arr[k] = negative[e];
            k++;
            e++;
        }        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends