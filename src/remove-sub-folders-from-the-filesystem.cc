// http://leetcode.com/problems/remove-sub-folders-from-the-filesystem/description/
#include "xxx.h"

class Solution {
public:
  vector<string> removeSubfolders(vector<string> &folder) {
    sort(folder.begin(), folder.end());
    auto last = folder[0];
    vector<string> ret;
    ret.push_back(last);
    for (int i = 1; i < folder.size(); ++i) {
      auto cur = folder[i];
      if (cur.size() > last.size() && cur[last.size()] == '/' &&
          cur.substr(0, last.size()) == last) {
        continue;
      }
      last = cur;
      ret.push_back(cur);
    }
    return ret;
  }
};
