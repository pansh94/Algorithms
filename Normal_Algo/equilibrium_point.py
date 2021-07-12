class Solution:

    def equilibriumPoint(self, A, N):
        if N == 1:
            return 1
        if N == 2:
            return -1

        rear_sum = A[0]
        tail_sum = A[N-1]
        r = 1
        t = N-2
        while(r < t):
            if rear_sum > tail_sum:
                tail_sum += A[t]
                t -= 1
            elif tail_sum > rear_sum:
                rear_sum += A[r]
                r += 1
            else:
                tail_sum += A[t]
                rear_sum += A[r]
                t -= 1
                r += 1

        if rear_sum == tail_sum:
            return (r+1)
        else:
            return -1


def main():
    T = int(input())

    while (T > 0):
        N = int(input())

        A = [int(x) for x in input().strip().split()]
        ob = Solution()

        print(ob.equilibriumPoint(A, N))

        T -= 1


if __name__ == "__main__":
    main()
