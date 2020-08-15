// http://leetcode.com/problems/1-bit-and-2-bit-characters/description/
#include "xxx.h"

class Solution {
public:
  // 被喷的特别厉害
  bool isOneBitCharacter(vector<int> &bits) {
    // 就看没有最后一位能不能形成有效字符
    bits.pop_back();
    const int n = bits.size();
    int i = 0;
    while (i < n) {
      // 能遇到0则肯定是单独的存在，直接忽略
      if (bits[i] == 0) {
        i++;
      } else {
        if (bits[i] == 1) {
          // 必须还有下一位
          if (i + 1 >= n) {
            return false;
          }
          // 下一位是0是1无所谓
          i += 2;
        }
      }
    }

    return true;
  }
};

int main() {
  Solution so;
  vector<int> input{1, 0, 0};
  auto ret = so.isOneBitCharacter(input);
  cout << ret << endl;
}
