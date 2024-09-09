//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr) {
        int zero = 0 ;
        int one = 0 ;
        int two = 0 ;
        for(auto i:arr){
            if(i == 0){
                zero++;
            }
            else if(i == 1){
                one++;
            }
            else{
                two++;
            }
        }
        
        int i = 0;
        while(zero != 0){
            arr[i++] = 0;
            zero--;
        }
        
        while(one != 0){
            arr[i++] = 1;
            one--;
        }        
        
        while(two != 0){
            arr[i++] = 2;
            two--;
        } 
        
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends