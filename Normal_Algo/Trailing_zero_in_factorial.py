

class Solution:
    def trailingZeroes(self, N):
        if N<5:
            return 0

        count = 0

        while(N > 5 ):
            N //= 5
            count += N

        return count


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        ob = Solution()
        ans = ob.trailingZeroes(N)
        print(ans)
