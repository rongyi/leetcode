// http://leetcode.com/problems/restore-ip-addresses/description/
#include "xxx.h"

class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> ret;
    // at least four digit,e.g. 1.1.1.1, 255.255.255.255 at most
    if (s.size() < 4 || s.size() > 12) {
      return ret;
    }
    string cur;
    dfs(s, 0, 1, ret, cur);

    return ret;
  }

private:
  void dfs(string &s, int i, int section, vector<string> &ret, string cur) {
    // the last
    if (section == 4) {
      auto tmp = s.substr(i);
      // too big or too small
      if (tmp.size() > 3 || tmp.size() < 1) {
        return;
      }
      // not valid
      if (tmp.size() > 1 && tmp[0] == '0') {
        return;
      }
      if (stoi(tmp) > 255) {
        return;
      }
      // now they are valid, and we push back cur
      cur += "." + tmp;
      // cout << cur <<  "four section" << endl;
      ret.push_back(cur);
      return;
    }
    auto total = s.substr(i);

    // test only char
    if (total.size() < 1) {
      return;
    }
    if (cur == "") {
      string single;
      single.push_back(s[i]);
      dfs(s, i + 1, section + 1, ret, single);
    } else {
      dfs(s, i + 1, section + 1, ret, cur + "." + s[i]);
    }
    // two digits
    if (total.size() < 2) {
      return;
    }
    auto tmp = s.substr(i, 2);
    if (tmp[0] == '0') {
      return;
    }
    if (cur == "") {
      dfs(s, i + 2, section + 1, ret, tmp);
    } else {
      dfs(s, i + 2, section + 1, ret, cur + "." + tmp);
    }

    // three digits
    if (total.size() < 3) {
      return;
    }
    tmp = s.substr(i, 3);
    if (tmp[0] == '0') {
      return;
    }
    auto three = stoi(tmp);
    if (three > 255) {
      return;
    }
    if (cur == "") {
      dfs(s, i + 3, section + 1, ret, tmp);
    } else {
      dfs(s, i + 3, section + 1, ret, cur + "." + tmp);
    }
  }
};

int main() {
  Solution so;
  auto ret = so.restoreIpAddresses("010010");
  for (auto &s : ret) {
    cout << s << endl;
  }
}
