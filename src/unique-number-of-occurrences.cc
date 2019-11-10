// http://leetcode.com/problems/unique-number-of-occurrences/description/
#include "xxx.h"

class Solution {
public:
  bool uniqueOccurrences(vector<int> &arr) {
    unordered_map<int, int> count;
    for (auto &num : arr) {
      ++count[num];
    }
    unordered_set<int> uniq;
    for (auto &kv : count) {
      if (uniq.find(kv.second) != uniq.end()) {
        return false;
      }
      uniq.insert(kv.second);
    }
    return true;
  }
};
