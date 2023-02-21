// http://leetcode.com/problems/simplify-path/description/
#include "xxx.hpp"

class Solution {
public:
  string simplifyPath(string path) {
    vector<string> dirs;
    stringstream ss(path);
    string cur;
    while (getline(ss, cur, '/')) {
      if (cur.empty() || cur == ".") {
        continue;
      }
      if (cur == "..") {
        if (!dirs.empty()) {
          dirs.pop_back();
        }
      } else {
        dirs.push_back(cur);
      }
    }
    if (dirs.empty()) {
      return "/";
    }
    ostringstream oss;
    for (auto &d : dirs) {
      oss << "/" << d;
    }
    return oss.str();
  }
};
