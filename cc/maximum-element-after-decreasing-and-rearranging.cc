// http://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/description/
#include "xxx.h"

class Solution {
public:
  // 完全看错题目了
  // 只能降和乱序
  int maximumElementAfterDecrementingAndRearranging(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    // set first to 1
    arr[0] = 1;
    // 尽可能的往上拉
    int max_value = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
      if (abs(arr[i] - arr[i - 1]) > 1) {
        arr[i] = arr[i - 1] + 1;
        max_value = arr[i];
      } else {
        // 两种情况： 和之前相等，或者大1
        max_value = max(max_value, arr[i]);
      }
    }

    return max_value;
  }
};

int main() {
  Solution so;
  vector<int> input{2, 2, 1, 2, 1};
  auto ret = so.maximumElementAfterDecrementingAndRearranging(input);
  cout << ret << endl;
}
