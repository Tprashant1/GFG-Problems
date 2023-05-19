#User function Template for python3
class Solution:
    def maximumSumSubarray (self,K,Arr,N):
        # code here 
        i=0
        j=0
        s=0
        ans=0
        while(j<N):
            s+=Arr[j]
            if j-i+1==K:
                ans=max(ans,s)
                s-=Arr[i]
                j+=1
                i+=1
            else:
                j+=1
        return ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        
        N,K = input().split()
        N = int(N)
        K = int(K)
        Arr = list( map(int,input().strip().split(" ")))

        ob = Solution()
        print(ob.maximumSumSubarray(K,Arr,N))
# } Driver Code Ends