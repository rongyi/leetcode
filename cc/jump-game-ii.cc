// http://leetcode.com/problems/jump-game-ii/description/
#include "xxx.hpp"

class Solution {
public:
  int jump(vector<int> &nums) {
    const int n = nums.size();
    int maximum = 0;
    int next_maximum = 0;
    int ret = 0;
    for (int i = 0; i < n - 1; i++) {
      next_maximum = max(next_maximum, nums[i] + i);
      if (i == maximum) {
        ret++;
        if (next_maximum >= n - 1) {
          return ret;
        }
        maximum = next_maximum;
      }
    }
    return ret;
  }
};
int main() {
  vector<int> input{2, 3, 1, 1, 4};
  Solution so;
  auto ret = so.jump(input);
  cout << ret << endl;
  return 0;
}
