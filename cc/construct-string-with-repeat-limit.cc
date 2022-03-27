// https://leetcode.com/problems/construct-string-with-repeat-limit/
#include "xxx.hpp"

class Solution {
public:
  string repeatLimitedString(string s, int limit) {
    // 'z' as the begin
    map<char, int, greater<int>> cnt;
    for (auto &c : s) {
      ++cnt[c];
    }
    string ret{};
    while (!cnt.empty()) {
      char cur = cnt.begin()->first;
      int total = cnt.begin()->second;
      int used = 0;
      cnt.erase(cur);
      while (total > 0) {
        used++;
        // we insert a gap for next
        if (used > limit) {
          if (cnt.empty()) {
            return ret;
          }
          auto it = cnt.begin();
          char gap = it->first;
          cnt[gap]--;
          if (cnt[gap] == 0) {
            cnt.erase(it);
          }
          ret.push_back(gap);
          // the used is for the next push_back of cur, not this gap
          used = 1;
        }
        ret.push_back(cur);
        total--;
      }
    }

    return ret;
  }
};

int main(int argc, char *argv[]) {
  // make z as first
  map<char, int, greater<int>> cnt;
  cnt['a'] = 10;
  cnt['z'] = 9;
  for (auto &kv : cnt) {
    cout << kv.first << " " << kv.second << endl;
  }

  return 0;
}
