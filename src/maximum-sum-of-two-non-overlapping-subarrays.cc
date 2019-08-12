// http://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/description/
#include "xxx.h"

class Solution {
public:
  int maxSumTwoNoOverlap(vector<int> &A, int L, int M) {
    return max(maxNoOverlap(A, L, M, A.size()),
               maxNoOverlap(A, M, L, A.size()));
  }

private:
  int maxNoOverlap(vector<int> &A, int L, int M, int len) {
    // 值放在 1 ... len + 1
    vector<int> left(len + 1, 0);
    // 值放在 0 ... len
    vector<int> right(len + 1, 0);

    int sum_left = 0;
    int sum_right = 0;
    for (int i = 0, j = len - 1; i < len; ++i, --j) {
      sum_left += A[i];
      sum_right += A[j];
      // left fix size: L
      if (i >= L) {
        sum_left -= A[i - L];
      }
      // right fix size: M
      if (j < len - M) {
        sum_right -= A[j + M];
      }

      left[i + 1] = max(left[i], sum_left);
      right[j] = max(right[j + 1], sum_right);
    }

    int ret = 0;
    for (auto i = 0; i < len; ++i) {
      // 这里有个问题： A[i]包含在哪个 sum里面？
      // right里面，前面的定义时的描述说明了
      ret = max(ret, left[i] + right[i]);
    }

    return ret;
  }
};

int main() {
  vector<int> input{1, 7, 3, 2, 8};
  int sum = 0;
  for (int i = 0; i < input.size(); ++i) {
    sum += input[i];
    if (i >= 2) {
      sum -= input[i - 2];
    }
    cout << sum << endl;
  }
  cout << "xx" << endl;
  sum = 0;
  for (int j = input.size() - 1; j >= 0; --j) {
    sum += input[j];
    if (j < input.size() - 2) {
      sum -= input[j + 2];
    }
    cout << sum << endl;
  }
}
