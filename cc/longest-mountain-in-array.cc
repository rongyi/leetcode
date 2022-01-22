// http://leetcode.com/problems/longest-mountain-in-array/description/
#include "xxx.hpp"

class Solution {
public:
  int longestMountain(vector<int> &A) {
    const int n = A.size();
    // mountain left i.e. 连续增加
    bool has_left = false;
    int start = -1;
    bool has_right = false;
    int ret = 0;
    for (int i = 1; i < n; i++) {
      if (A[i] > A[i - 1]) {
        if (!has_left || has_right) {
          has_left = true;
          start = i - 1;
          has_right = false;
        }
      } else if (A[i] < A[i - 1]) {
        if (has_left && !has_right) {
          has_right = true;
        }

        if (has_left && has_right) {
          ret = max(ret, i - start + 1);
        }
      } else {
        // equal not allowed
        has_left = false;
        has_right = false;
        start = -1;
      }
    }
    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{2, 3, 3, 2, 0, 2};
  auto ret = so.longestMountain(input);
  cout << ret << endl;
}
