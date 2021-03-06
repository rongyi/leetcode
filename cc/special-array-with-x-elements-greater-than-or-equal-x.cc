// http://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/description/
#include "xxx.h"

class Solution {
public:
  int specialArray(vector<int> &nums) {
    map<int, int> cache;
    for (auto &num : nums) {
      cache[num]++;
    }
    auto max = *max_element(nums.begin(), nums.end());
    for (int i = 0; i <= max; ++i) {
      if (check(cache, i)) {
        return i;
      }
    }
    return -1;
  }

private:
  bool check(map<int, int> &cache, int cur) {
    int count = 0;
    for (auto iter = cache.lower_bound(cur); iter != cache.end(); ++iter) {
      count += iter->second;
    }
    if (count == cur) {
      return true;
    }
    return false;
  }
};

int main() {}
