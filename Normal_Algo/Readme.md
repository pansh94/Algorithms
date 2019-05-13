# Time complexity analysis
Running time complexity of a progrom depends on :
1. Single vs multiple processor
2. Read and write speed to memory
3. 32 bit or 64 bit arch
4. Rate of growth of time taken with respect to input.

## Asymptotic notations
### 1. Big O
f(n) = 5n^2 + 2n + 1
suppose n->infinity then n^2 will only relevent so O(f(n)) = n^2
It always give us upper bound of rate of growth of time.

### 2. Omega 
```
Ω (g(n)) = {f(n): there exist positive constants c and
                  n0 such that 0 <= c*g(n) <= f(n) for
                  all n >= n0}.
```
It gives us lower bound of growth of rate of equation.

### 3. Theta
```
Θ(g(n)) = {f(n): there exist positive constants c1, c2 and n0 such 
                 that 0 <= c1*g(n) <= f(n) <= c2*g(n) for all n >= n0}
```
The above definition means, if f(n) is theta of g(n), then the value f(n) is always between c1*g(n) and c2*g(n) for large values of n (n >= n0). The definition of theta also requires that f(n) must be non-negative for values of n greater than n0.

# Space time complexity
Space complexity is a measure of how efficient your code is in terms of memory used.
```
vector<int> V;
for (int i = 0; i < N; i++) V.push_back(i);
```
The code snippet ends up creating a vector of size N. So, space complexity of the code is O(N).

# Algo Links
1. [Kadane's Algo for largest sum contiguous subarray](https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/)
2. [Longest Common Subsequence DP-Recurr](https://www.geeksforgeeks.org/longest-common-subsequence/)
3. [0-1 Knapsack DP](https://www.geeksforgeeks.org/knapsack-problem/)
4. [String C++](http://www.cplusplus.com/reference/string/string/)
