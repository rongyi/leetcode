// http://leetcode.com/problems/reformat-the-string/description/
#include "xxx.hpp"

class Solution {
public:
  string reformat(string s) {
    string sgroup;
    string num_group;
    for (auto c : s) {
      if (isdigit(c)) {
        num_group.push_back(c);
      } else {
        sgroup.push_back(c);
      }
    }

    int sn = sgroup.size();
    int nn = num_group.size();
    if (abs(sn - nn) > 1) {
      return "";
    }

    // r is the longer one
    auto merge = [](string &l, string &r) -> string {
      string ret;
      int i = 0;
      for (; i < l.size(); ++i) {
        ret.push_back(r[i]);
        ret.push_back(l[i]);
      }
      if (i < r.size()) {
        ret.push_back(r[i]);
      }
      return ret;
    };
    if (sn <= nn) {
      return merge(sgroup, num_group);
    }
    return merge(num_group, sgroup);
  }
};
