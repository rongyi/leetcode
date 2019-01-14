// http://leetcode.com/problems/single-number-ii/description/
#include "xxx.h"

class Solution {
public:
  // 重复出现三次，只能是统计了
  int singleNumber(vector<int> &nums) {
    const int bitwidth = sizeof(int) * 8;
    vector<int> count(bitwidth, 0);

    for (auto i : nums) {
      for (int j = 0; j < bitwidth; ++j) {
        count[j] += ((i >> j) & 0x1);
        count[j] %= 3;
        if (count[j] == 0) {
        }
      }
    }
    // now what count left is the number represent in 2 base, we calculate it
    int ret = 0;
    for (int i = 0; i < bitwidth; i++) {
      ret += (count[i] << i);
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{0,1,0,1,0,1,99};
  auto ret = so.singleNumber(input);
  cout << ret << endl;
}
