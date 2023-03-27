// http://leetcode.com/problems/single-number-ii/description/
#include "xxx.hpp"

class Solution {
public:
  // 重复出现三次，只能是统计了
  int singleNumber(vector<int> &nums) {
    vector<int> cnt(32, 0);
    for (auto &num : nums) {
      for (int i = 0; i < 32; i++) {
        cnt[i] = (cnt[i] + ((num >> i) & 1)) % 3;
      }
    }
    int ret = 0;
    for (int i = 0; i < cnt.size(); i++) {
      ret |= (cnt[i] << i);
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{0, 1, 0, 1, 0, 1, 99};
  auto ret = so.singleNumber(input);
  cout << ret << endl;
}
