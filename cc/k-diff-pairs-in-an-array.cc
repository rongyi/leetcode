// http://leetcode.com/problems/k-diff-pairs-in-an-array/description/
#include "xxx.hpp"

class Solution {
public:
  int findPairs(vector<int> &nums, int k) {
    unordered_map<int, int> count;
    for (auto i : nums) {
      count[i]++;
    }
    int ret = 0;
    for (auto &kv : count) {
      if (k == 0) {
        if (kv.second >= 2) {
          ret += 1;
        }
      } else {
        if (count.count(kv.first + k)) {
          ret += 1;
        }
      }
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{1, 2, 3, 4, 5};
  so.findPairs(input, 1);
}
