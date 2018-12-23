// http://leetcode.com/problems/rotate-function/description/
#include "xxx.h"

class Solution {
public:
  int maxRotateFunctionTLE(vector<int> &A) {
    if (A.empty()) {
      return 0;
    }
    const int n = A.size();

    long long ret = numeric_limits<int>::min();
    for (int i = 0; i < n; i++) {
      int start = (n - i) % n;
      long long cur = 0;
      for (int j = 0; j < n; j++) {
        cur += A[(start + j) % n] * j;
      }
      ret = max(ret, cur);
    }

    return ret;
  }

  // F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
  // F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) + 4 * 6 = 0 + 4 + 6 + 6 = 16 + 4 * 6
  // 找出这样的规律， f1 比 f0 多出一个sum然后再减去
  // F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
  // F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
  int maxRotateFunction(vector<int> &A) {
    if (A.empty()) {
      return 0;
    }
    const int n = A.size();
    const int sum = accumulate(A.begin(), A.end(), 0);

    int initial = 0;
    for (int i = 0; i < n; i++) {
      initial += A[i] * i;
    }

    int ret = initial;
    for (int j = 1; j < n; j++) {
      initial += sum - n * A[n - j];
      ret = max(ret, initial);
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{-2147483648, -2147483648};
  auto ret = so.maxRotateFunctionTLE(input);
  cout << ret << endl;
}
