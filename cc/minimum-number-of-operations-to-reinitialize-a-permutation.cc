// http://leetcode.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/description/
#include "xxx.h"

class Solution {
public:
  int reinitializePermutation(int n) {
    int pos = n / 2;
    int ret = 1;
    // 算的就是第二个位置上的数字什么时候到1
    // 结合下面的print看
    // 0 1 2 3 4 5 6 7 8 9
    // 0 5 1 6 2 7 3 8 4 9
    // 0 7 5 3 1 8 6 4 2 9
    // 0 8 7 6 5 4 3 2 1 9
    // 0 4 8 3 7 2 6 1 5 9
    // 0 2 4 6 8 1 3 5 7 9
    // 0 1 2 3 4 5 6 7 8 9

    while (pos != 1) {
      ret++;
      if (pos & 1) {
        pos = n / 2 + (pos - 1) / 2;
      } else {
        pos = pos / 2;
      }
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input;
  for (int i = 0; i < 10; ++i) {
    input.push_back(i);
  }

  vector<int> gen(10, 0);
  for (int r = 0; r < 10; ++r) {
    for (int i = 0; i < 10; ++i) {
      if (i & 1) {
        gen[i] = input[10 / 2 + (i - 1) / 2];
      } else {
        gen[i] = input[i / 2];
      }
    }

    for (auto i : input) {
      cout << i << " ";
    }
    cout << endl;
    input = gen;
  }
}
