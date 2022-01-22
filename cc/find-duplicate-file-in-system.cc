// http://leetcode.com/problems/find-duplicate-file-in-system/description/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<string>> findDuplicate(vector<string> &paths) {
    unordered_map<string, vector<string>> content;
    for (auto p : paths) {
      int n = p.size();
      int i = 0;
      string cur_dir_prefix;
      while (i < n) {
        int j = i;
        while (j < n && p[j] != ' ') {
          j++;
        }
        string cur = p.substr(i, j - i);
        // this mean cur is dir prefix
        if (i == 0) {
          cur_dir_prefix = cur;
        } else {
          // a part for file and it's content
          // length of file content is in the range of [1,50]
          // so file will not be empty
          string c = cur.substr(cur.find('(') + 1);
          // eject last )
          c.pop_back();

          string f = cur.substr(0, cur.find('('));

          content[c].push_back(cur_dir_prefix + "/" + f);
        }
        // jump over, please do not stay on space
        i = j + 1;
      }
    }
    vector<vector<string>> ret{};

    for (auto kv : content) {
      if (kv.second.size() > 1) {
        ret.push_back(kv.second);
      }
    }
    return ret;
  }
};
