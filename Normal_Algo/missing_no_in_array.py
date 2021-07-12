
class Solution:
    def MissingNumber(self,array,n):
        sum_ap = (n*(1+n))/2
        sum_arr = 0
        for i in range(n-1):
            sum_arr = sum_arr + array[i]
        return(int(sum_ap-sum_arr))


t=int(input())
for _ in range(0,t):
    n=int(input())
    a=list(map(int,input().split()))
    s=Solution().MissingNumber(a,n)
    print(s)
