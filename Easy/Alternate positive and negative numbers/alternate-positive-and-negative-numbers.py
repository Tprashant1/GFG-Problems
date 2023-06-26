#User function Template for python3

class Solution:
    def rearrange(self,arr, n):
        # code here
        # p=arr[0]
        l=[]
        r=[]
        res=[]
        for i in range(n):
            if(arr[i]>=0):
                l.append(arr[i])
            else:
                r.append(arr[i])
        i=0
        j=0
        while(i<len(l) and j<len(r)):
            res.append(l[i])
            res.append(r[j])
            i+=1
            j+=1
        while(i<len(l)):
            res.append(l[i])
            i+=1
        while(j<len(r)):
            res.append(r[j])
            j+=1
        arr[:] = res[:]
        return arr
        
        
            
        

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	tc = int(input())
	while tc > 0:
		n = int(input())
		arr = list(map(int, input().strip().split()))
		ob = Solution()
		ob.rearrange(arr, n)
		for x in arr:
			print(x, end=" ")
		print()
		tc -= 1

# } Driver Code Ends