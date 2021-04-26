// http://leetcode.com/problems/create-sorted-array-through-instructions/description/
#include "xxx.h"

class Solution {
public:
  // https://halfrost.com/binary_indexed_tree/
  int createSortedArray(vector<int> &instructions) {
    data_.resize(1e5 + 1);
    int ret = 0;
    const int n = instructions.size();
    const int mod = 1e9 + 7;
    for (int i = 0; i < n; ++i) {
      ret =
          (ret + min(get(instructions[i] - 1), i - get(instructions[i]))) % mod;
      update(instructions[i]);
    }
    return ret;
  }

private:
  void update(int x) {
    while (x < 100001) {
      data_[x]++;
      x += x & -x;
    }
  }
  int get(int x) {
    int ret = 0;
    while (x > 0) {
      ret += data_[x];
      x -= x & -x;
    }
    return ret;
  }

private:
  vector<int> data_;
};
