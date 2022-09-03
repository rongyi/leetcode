// https://leetcode.com/problems/count-special-integers/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/count-special-integers/discuss/2422436/Counting-%2B-DFS
  int countSpecialNumbers(int n) {
    string s = to_string(n);
    int ret = dfs(0, 0, s);
    for (int i = 1; i < s.size(); ++i) {
      ret += 9 * count(i - 1, 9);
    }
    return ret;
  }

private:
  int count(int i, int m) {
    int ret = 1;
    for (int j = 0; j < i; ++j) {
      ret *= m--;
    }
    return ret;
  }
  int dfs(int cur_pos, int mask, string &s) {
    if (cur_pos >= s.size()) {
      return 1;
    }
    int ret = 0;
    int cur = s[cur_pos] - '0';
    // 0 can not be leading zero
    for (int i = cur_pos > 0 ? 0 : 1; i < cur; ++i) {
      // current num is not used
      // then we can use it for current pos
      if ((mask & (1 << i)) == 0) {
        ret += count(s.size() - cur_pos - 1, 9 - cur_pos);
      }
    }
    // no colission? then go on
    return ret + ((mask & (1 << cur)) == 0
                      ? dfs(cur_pos + 1, mask + (1 << cur), s)
                      : 0);
  }
};

int main(int argc, char *argv[]) {
  Solution so;

  return 0;
}
