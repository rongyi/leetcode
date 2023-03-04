// http://leetcode.com/problems/restore-ip-addresses/description/
#include "xxx.hpp"

class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> ret;

    string cur;
    dfs(s, ret, 0, "", 0);

    return ret;
  }

private:
  // idx: current pos at s
  // cnt: total sections (3.2.3.4) -> 4
  void dfs(string &s, vector<string> &ret, int idx, string cur, int cnt) {
    if (cnt > 4) {
      return;
    }
    if (cnt == 4 && idx == s.size()) {
      // "1.2.3.4."
      cur.pop_back();
      ret.push_back(cur);
      return;
    }
    for (int l = 1; l < 4; l++) {
      if (idx + l > s.size()) {
        break;
      }
      string chunk = s.substr(idx, l);
      if (chunk.size() > 1 && chunk[0] == '0') {
        continue;
      }
      if (stoi(chunk) > 255) {
        continue;
      }
      dfs(s, ret, idx + l, cur + chunk + ".", cnt + 1);
    }
  }
};

