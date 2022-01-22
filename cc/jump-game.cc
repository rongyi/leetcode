// http://leetcode.com/problems/jump-game/description/
#include "xxx.hpp"

class Solution {
public:
  bool canJump(vector<int> &nums) {
    const int n = nums.size();
    int reach = 0;
    for (int i = 0; i <= reach; ++i) {
      reach = max(reach, nums[i] + i);
      if (reach >= n - 1) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  Solution so;
  vector<int> input{3, 2, 1, 0, 4};
  auto ret = so.canJump(input);
  cout << ret << endl;
}
