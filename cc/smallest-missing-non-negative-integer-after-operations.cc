// https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/
#include "xxx.hpp"

class Solution {
public:
  int findSmallestInteger(vector<int> &nums, int value) {
    map<int, int> group_by_rem;
    for (auto &num : nums) {
      int val = num % value;
      if (val < 0) {
        val = (val + value) % value;
      }
      group_by_rem[val]++;
    }
    int ret = 0;
    int group_sz = numeric_limits<int>::max();
    for (; ret < value; ret++) {
      if (!group_by_rem.count(ret)) {
        return ret;
      }
      group_sz = min(group_sz, group_by_rem[ret]);
    }

    int base = value * group_sz;
    for (int i = 0; i < value; i++) {
      if (group_by_rem[i] > group_sz) {
        base++;
      } else {
        break;
      }
    }
    return base;
  }
};

int main() {
  cout << ((-3 % 4)) << endl;
  vector<int> input{0, -3};
  Solution so;
  so.findSmallestInteger(input, 5);
}
