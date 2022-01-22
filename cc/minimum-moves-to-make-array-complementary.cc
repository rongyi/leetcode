// http://leetcode.com/problems/minimum-moves-to-make-array-complementary/description/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/minimum-moves-to-make-array-complementary/discuss/952773/PythonJava-simple-O(max(n-k))-method
  int minMoves(vector<int> &nums, int limit) {
    int ret = numeric_limits<int>::max();
    const int n = nums.size();
    unordered_map<int, int> delta;

    // clang-format off
    // 2 <= T < min(A, B) + 1, we need 2 operations to make both A, B smaller
    // min(A, B) + 1 <= T < A + B, we need 1 operation to make the larger one out of A and B smaller
    // T = A + B, we need 0 operation
    // A + B < T <= max(A, B) + limit, we need 1 operation to make the smaller one out of A and B larger ==> 最小的改成limit即可，超过就要改两个了
    // max(A, B) + limit < T <= 2 * limit, we need 2 operation to make both A, B larger

    // if x is the increment performed on range [L,R] then change delta[L] += x and delta[R+1] -= x
    // Why subtracting on delta[R+1] ?
    // while performing "prefix sum" over delta array, x is gets incremented for all index in range [L,R]. This is the reason of delta[L] += x for only L. Prefix sum does the rest of updates.
    // We want to stop adding x beyond R so subtract x from R+1
    // This is range update in 0(1) (difference array)

    // So, the update steps looks like
    // [ 2, min(A+B)+1, A+B, A+B+1, max(A,B)+limit+1, 2*limit ]

    // delta[2]+=2, delta[min(A,B)+1] -=2
    // delta[min(A,B)+1] +=1, delta[A+B] -=1
    // delta[A+B] +=0, delta[A+B+1] -=0
    // delta[A+B+1] +=1, delta[max(A,B)+limit+1)] -=1
    // delta[max(A,B)+limit+1)]+=2

    // clang-format on
    for (int i = 0; i < nums.size() / 2; i++) {
      int a = nums[i];
      int b = nums[n - i - 1];

      delta[2] += 2;
      // delta[min(a, b) + 1] -= 2;
      // delta[min(a, b) + 1] += 1;
      // ==>
      delta[min(a, b) + 1] -= 1;

      delta[a + b] -= 1;
      // delta[a + b] += 0;
      // delta[a + b + 1] -= 0;
      delta[a + b + 1] += 1;
      // delta[max(a, b) + limit + 1] -= 1;
      // delta[max(a, b) + limit + 1] += 2;
      // ==>
      delta[max(a, b) + limit + 1] += 1;
    }
    int cur = 0;
    for (int i = 2; i <= 2 * limit; ++i) {
      cur += delta[i];
      ret = min(ret, cur);
    }

    return ret;
  }
};
