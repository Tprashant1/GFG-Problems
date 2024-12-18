//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    bool isPossible(vector<int> &arr, int k,int mid){
        int studentCount = 1;
        int lastPage = 0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(lastPage+arr[i] <= mid){
                lastPage += arr[i];
            }
            else{
                studentCount++;
                if(studentCount > k || arr[i] > mid){
                    return false;
                }
                lastPage = arr[i];
            }
        }
        return true;
    }
  
    int findPages(vector<int> &arr, int k) {
        if(k == 1){
            int ans = 0 ;
            for(auto i:arr){
                ans += i;
            }
            return ans;
        }
        
        int n = arr.size();
        if(k > n){
            return -1;
        }
        
        int s = 0;
        int sum = 0 ;
        for(auto i:arr){
            sum += i;
        }
        
        int e = sum;
        int ans = -1;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(isPossible(arr,k,mid)){
                ans = mid;
                e = mid-1;
            }
            else{
                s= mid+1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends