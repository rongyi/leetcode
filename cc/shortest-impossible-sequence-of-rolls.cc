// https://leetcode.com/problems/shortest-impossible-sequence-of-rolls/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/shortest-impossible-sequence-of-rolls/discuss/2322280/JavaC%2B%2BPython-One-Pass-O(K)-Space
  int shortestSequence(vector<int> &rolls, int k) {
    set<int> uniq;
    int full_group = 0;
    for (auto r : rolls) {
      uniq.insert(r);
      if (uniq.size() == k) {
        full_group++;
        uniq.clear();
      }
    }

    return full_group + 1;
  }
};
