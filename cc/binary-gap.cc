// https://leetcode.com/problems/binary-gap/description/
#include "xxx.h"

class Solution {
public:
  int binaryGap(int N) {
    // has only one 1
    if ((N & (N - 1)) == 0) {
      return 0;
    }

    string n = bitset<32>(N).to_string();
    int ret = 1;
    for (int i = 0; i < 32;) {
      // search left and right till we met 1
      if (n[i] == '0') {
        bool hasleft = false;
        if (i - 1 >= 0 && n[i - 1] == '1') {
          hasleft = true;
        }

        int dis = 1;
        while (i < 32 && n[i] == '0') {
          ++i;
          ++dis;
        }
        if (i < 32) {
          if (hasleft) {
            ret = max(ret, dis);
          }
        }
      } else {
        ++i;
      }
    }
    return ret;
  }
};

int main() {
  Solution so;
  auto ret = so.binaryGap(8);
  cout << ret << endl;
}
