class Solution:
    def binary_search(self, Arr, k, r, l):
        if r<=l:
            mid = (l+r)//2
            if Arr[mid] == k :
                return mid

            elif Arr[mid] > k:
                return self.binary_search(Arr, k, r, mid-1)

            else:
                return self.binary_search(Arr, k, mid+1, l)

        else :
            return ((l+r)//2 + 1)

    def searchInsertK(self, Arr, N, k):
        l = N-1
        r =0
        index = self.binary_search(Arr, k, r, l)
        return index


if __name__ == '__main__':
    t = int(input())
    for _ in range (t):
        N = int(input())
        Arr = input().split()
        for itr in range(N):
            Arr[itr] = int(Arr[itr])
        k = int(input())
        ob = Solution()
        print(ob.searchInsertK(Arr, N, k))
