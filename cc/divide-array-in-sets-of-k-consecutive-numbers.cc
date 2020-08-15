// http://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/description/
#include "xxx.h"

class Solution {
public:
  bool isPossibleDivide(vector<int> &nums, int k) {
    if (nums.size() % k) {
      return false;
    }

    unordered_set<int> uniq;
    unordered_map<int, int> count;
    for (auto &n : nums) {
      uniq.insert(n);
      ++count[n];
    }
    vector<int> lst(uniq.begin(), uniq.end());
    sort(lst.begin(), lst.end());
    for (int i = 0; i < lst.size(); ++i) {
      if (!count[lst[i]]) {
        continue;
      }

      while (count[lst[i]]) {
        int start = lst[i];
        auto group = k;
        while (group) {
          if (!count[start]) {
            return false;
          }
          --count[start];
          start++;
          --group;
        }
      }
    }
    return true;
  }
};
