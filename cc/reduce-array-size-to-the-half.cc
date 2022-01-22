// http://leetcode.com/problems/reduce-array-size-to-the-half/description/
#include "xxx.hpp"

class Solution {
public:
  int minSetSize(vector<int> &arr) {
    const int n = arr.size();
    unordered_map<int, int> count;
    set<pair<int, int>> s;
    for (auto &num : arr) {
      count[num]++;
    }
    for (auto kv : count) {
      s.insert({kv.second, kv.first});
    }
    int left = n;
    int ret = 0;
    for (auto it = s.rbegin(); it != s.rend(); it++) {
      left -= it->first;
      ret++;

      if (left <= n / 2) {
        return ret;
      }
    }


    return ret;
  }
};
