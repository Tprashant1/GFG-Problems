#User function Template for python3


def LargButMinFreq(arr,n):
    #code here
    d={}
    l=[]
    for i in arr:
        if i not in d:
            d[i] = 1
        else:
            d[i] +=1 
    res = min(d.values())
    for key in d.keys():
        if d[key] == res:
            l.append(key)
    return max(l)

#{ 
 # Driver Code Starts
#Initial Template for Python 3

t = int(input())
#Iterating over test cases
for _ in range(t):
    n = int(input())
    arr = [int(x) for x in input().split()]
    print(LargButMinFreq(arr, n))
# } Driver Code Ends