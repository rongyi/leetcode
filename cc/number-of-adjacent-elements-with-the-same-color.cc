// https://leetcode.com/problems/number-of-adjacent-elements-with-the-same-color/
#include "xxx.hpp"

class Solution {
public:
  // shitty problems
  // adjacent means group
  vector<int> colorTheArray(int n, vector<vector<int>> &queries) {
    vector<int> nums(n, 0);
    vector<int> ret;
    int cnt = 0;
    // {index, color}
    for (auto &q : queries) {
      int i = q[0];
      int val = q[1];
      if (nums[i] && i - 1 >= 0 && nums[i - 1] == nums[i]) {
        cnt--;
      }
      if (nums[i] && i + 1 < n && nums[i + 1] == nums[i]) {
        cnt--;
      }
      nums[i] = val;

      if (i - 1 >= 0 && nums[i - 1] == nums[i]) {
        cnt++;
      }
      if (i + 1 < n && nums[i + 1] == nums[i]) {
        cnt++;
      }
      ret.push_back(cnt);
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<vector<int>> input{{0, 2}, {1, 2}, {3, 1}, {1, 1}, {2, 1}};
  so.colorTheArray(4, input);
}
