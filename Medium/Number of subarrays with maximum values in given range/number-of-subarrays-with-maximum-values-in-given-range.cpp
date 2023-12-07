//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long countSubarrays(int a[], int n, int L, int R)
    {
        long long int i = 0;
        long long int s =0;
        long long int c = 0;
        for(long long int j=0;j<n;j++){
            if(a[j]>=L && a[j]<=R){
                s = j-i+1 ;
            }
            if(a[j]>R){
                s=0;
                i=j+1;
            }
            c +=s;
        }
        return c ;
        
    }
};

//{ Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}

// } Driver Code Ends