class Solution:
    def findIndexes(self, v, x, r, l):
        if r<=l:
            mid = (l+r)//2
            if v[mid] == x:
                return mid
            elif v[mid]>x:
                return self.findIndexes(v,x,r,mid-1)
            else:
                return self.findIndexes(v,x,mid+1,l)
        else:
            return -1

    def indexes(self, v, x):
        index = self.findIndexes(v, x, 0, len(v)-1)
        if index==-1 :
            return {-1, -1}
        else:
            min = -1
            max = -1
            temp = index
            while (True):
                if temp>=0:
                    min = temp
                    temp = self.findIndexes(v, x, 0, temp - 1)
                else:
                    break
            temp = index
            while (True):
                if temp>=0:
                    max = temp
                    temp = self.findIndexes(v, x, temp + 1, len(v)-1)
                else:
                    break
            return [min, max]


def main():
    T = int(input())

    while (T > 0):
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        k = int(input())
        obj = Solution()
        ans = obj.indexes(a, k)
        if ans[0] == -1 and ans[1] == -1:
            print(-1)
        else:
            print(ans[0], end=' ')
            print(ans[1])

        T -= 1


if __name__ == "__main__":
    main()
