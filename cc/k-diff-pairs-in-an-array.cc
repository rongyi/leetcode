// http://leetcode.com/problems/k-diff-pairs-in-an-array/description/
#include "xxx.hpp"

class Solution {
public:
  int findPairs(vector<int> &nums, int k) {
    if (k < 0) {
      return 0;
    }
    unordered_map<int, int> count;
    for (auto i : nums) {
      count[i]++;
    }
    if (k == 0) {
      int ret = 0;
      for (auto kv : count) {
        if (kv.second > 1) {
          ret++;
        }
      }
      return ret;
    }

    set<pair<int, int>> uniq;
    for (auto i : nums) {
      auto it = count.find(i + k);
      if (it == count.end()) {
        continue;
      }
      uniq.insert({min(i, it->first), max(i, it->first)});

      it = count.find(i - k);
      if (it == count.end()) {
        continue;
      }
      uniq.insert({min(i, it->first), max(i, it->first)});
    }
    return uniq.size();
  }
};

int main() {
  Solution so;
  vector<int> input{1, 2, 3, 4, 5};
  so.findPairs(input, 1);
}
