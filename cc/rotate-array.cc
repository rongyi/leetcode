// http://leetcode.com/problems/rotate-array/description/
#include "xxx.h"

class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    const int n = nums.size();
    if (n == 0) {
      return;
    }
    k %= n;
    if (k == 0) {
      return;
    }
    for (int i = n - k, compensate = 0; i < n; ++i) {
      nums.insert(nums.begin() + compensate, nums[i + compensate]);
      compensate++;
    }
    nums.resize(n);
  }
};

int main() {
  Solution so;
  vector<int> input{1, 2, 3, 4, 5, 6, 7};

  so.rotate(input, 3);
  for (auto i : input) {
    cout << i << " ";
  }
  cout << endl;
}
