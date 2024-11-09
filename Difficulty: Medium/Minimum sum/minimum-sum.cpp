//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
   void reverseString(string &str) {
        int i = 0, j = str.size() - 1;
        while (i < j) {
            swap(str[i], str[j]);
            i++;
            j--;
        }
    }
    
    string removeLeadingZero(string s){
        for(int i=0;i<s.size();i++){
            if(s[i] != '0'){
                return s.substr(i);
            }
        }
        return "";
    }
    
    string minSum(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        string curr = "";
        string temp = "";

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0){
                curr += to_string(arr[i]);
            }
            else{
                temp += to_string(arr[i]);
            } 
        }

        curr = removeLeadingZero(curr);
        temp = removeLeadingZero(temp);
        int carry = 0, i = curr.size() - 1, j = temp.size() - 1;
        string ans = "";

   
        while (i >= 0 || j >= 0 || carry != 0) {
            int digit1 = (i >= 0) ? curr[i] - '0' : 0;
            int digit2 = (j >= 0) ? temp[j] - '0' : 0;
            int sum = digit1 + digit2 + carry;
        
            ans += to_string(sum % 10);
            carry = sum / 10;
        
            i--;
            j--;
        }

    
        reverseString(ans);
        ans = removeLeadingZero(ans);
    
        return ans;
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends