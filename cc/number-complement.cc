// http://leetcode.com/problems/number-complement/description/
#include "xxx.hpp"

class Solution {
public:
  int findComplement(int num) {
    int ret = 0;
    int bitcount = 0;
    int copy = num;
    // 慢慢来，无需 num &= (num - 1) 这样的加速
    while (copy) {
      bitcount++;
      copy >>= 1;
    }
    for (int i = 0; i < bitcount; ++i) {
      ret |= ((((num >> i) & 1) ^ 1) << i);
    }
    return ret;
  }
};
int main() {
  Solution so;
  auto ret = so.findComplement(16);
  cout << ret << endl;
}
