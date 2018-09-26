// http://leetcode.com/problems/jump-game-ii/description/
#include "one.h"

class Solution {
public:
  int jump(vector<int> &nums) {
    const int n = nums.size();
    int ret = 0;
    int range = 0;
    int cur = 0;

    for (int i = 0; i < n; ++i) {
      // 出了当前最远跳的势力范围
      if (i > range) {
        ret++;
        range = cur;
      }
      cur = max(cur, i + nums[i]);
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
