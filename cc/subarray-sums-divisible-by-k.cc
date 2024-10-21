// http://leetcode.com/problems/subarray-sums-divisible-by-k/description/
#include "xxx.hpp"

class Solution {
public:
  int subarraysDivByK(vector<int> &A, int K) {
    // About the problems - sum of contiguous subarray , prefix sum is a common technique.
    // Another thing is if sum[0, i] % K == sum[0, j] % K, sum[i + 1, j] is divisible by by K.
    // So for current index j, we need to find out how many index i (i < j) exist that has the same mod of K.
    // Now it easy to come up with HashMap <mod, frequency>
    vector<int> count(K, 0);
    // if first sum == 0, it match K % sum == 0
    count[0] = 1;
    int prefix = 0;
    int ret = 0;

    for (auto a : A) {
      prefix = (prefix + a % K + K) % K;
      ret += count[prefix]++;
    }

    return ret;
  }
  int subarraysDivByKTLE(vector<int> &A, int K) {
    const int n = A.size();
    vector<int> sums(n + 1, 0);
    for (int i = 0; i < n; i++) {
      // put value to 1 .. n
      sums[i + 1] = sums[i] + A[i];
    }
    int ret = 0;

    for (int count = 0; count < n; count++) {
      for (int start = 0; start + count < n; start++) {
        int cur_sum = sums[start + count + 1] - sums[start];
        if (cur_sum % K == 0) {
          ++ret;
        }
      }
    }

    return ret;
  }
};
