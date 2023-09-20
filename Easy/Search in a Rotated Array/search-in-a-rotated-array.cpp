//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int getPivot(int A[],int l,int h){
    int s = l ;
    int e = h;
    int mid = s+(e-s)/2 ;
    while(s<e){
        if(A[mid]>=A[0]){
            s = mid+1 ; 
        }
        else{
            e = mid;
        }
        mid = s+(e-s)/2 ;
    }
    return s;

}

    int BinarSearch(int A[],int s,int e,int k){
    int start = s ;
    int end = e ;
    int mid = start+(end-start)/2 ;
    while(start<=end){
        if(A[mid]==k){
            return mid ;
        }
        else if(A[mid]<k){
            start = mid+1 ;
        }
        else{
            end = mid-1 ;
        }
        mid = start+(end-start)/2 ;
    }
    return -1 ;

}
    int search(int A[], int l, int h, int k){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function hereint pivot = getPivot(arr,n);
    int pivot = getPivot(A,l,h) ;
    if(k>=A[pivot] && k<=A[h]){
        return BinarSearch(A,pivot,h,k);
    }
    else{
        return BinarSearch(A,l,pivot-1,k);
    }
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends