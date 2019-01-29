// http://leetcode.com/problems/arithmetic-slices/description/
#include "xxx.h"

class Solution {
public:
  int numberOfArithmeticSlices(vector<int> &A) {
    if (A.size() < 3) {
      return 0;
    }
    const int n = A.size();
    int ret = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 2; j < n; ++j) {
        // cout << "testing " << i << "   " << j << endl;
        if (isArithmetic(A, i, j)) {
          ++ret;
        }
      }
    }
    return ret;
  }

public:
  // i, j included
  bool isArithmetic(vector<int> &nums, int i, int j) {
    auto delta = nums[i + 1] - nums[i];
    for (int k = i + 2; k <= j; k++) {
      if (nums[k] - nums[k - 1] != delta) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution so;
  vector<int> input{1, 2, 3, 4};
  auto ret = so.numberOfArithmeticSlices(input);
  // auto ret = so.isArithmetic(input, 0, 3);
  cout << ret << endl;
}
