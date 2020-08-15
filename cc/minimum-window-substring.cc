// http://leetcode.com/problems/minimum-window-substring/description/
#include "xxx.h"

class Solution {
public:
  string minWindow(string source, string target) {
    unordered_map<char, int> target_count;
    unordered_map<char, int> current_count;
    for (auto t : target)
      ++target_count[t];
    int begin = 0;
    int end = 0;
    const int n = source.length();
    int min = std::numeric_limits<int>::max();
    string ret;

    // 先跑end，跑到一个满足条件的，再紧缩begin，找到一个满足条件最小的
    for (; end < n; ++end) {
      if (target_count.find(source[end]) != target_count.end())
        ++current_count[source[end]];
      while (every(current_count, target_count)) {
        const int cur_len = end - begin + 1;
        if (cur_len < min) {
          min = cur_len;
          ret = source.substr(begin, cur_len);
        }
        if (current_count.find(source[begin]) != current_count.end()) {
          --current_count[source[begin]];
        }
        ++begin;
      }
    }
    return min == std::numeric_limits<int>::max() ? "" : ret;
  }

private:
  bool every(unordered_map<char, int> &current_count,
             unordered_map<char, int> &target_count) {
    for (auto kv : target_count) {
      if (current_count[kv.first] < kv.second)
        return false;
    }

    return true;
  }
};
