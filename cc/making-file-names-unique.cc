// http://leetcode.com/problems/making-file-names-unique/description/
#include "xxx.h"

class Solution {
public:
  // 喷的很惨
  vector<string> getFolderNames(vector<string> &names) {
    unordered_map<string, int> count;

    // current smallest postive duplicate index;
    unordered_map<string, int> index;
    vector<string> ret;
    for (auto &name : names) {
      // 不能提前，每一步添加
      count[name]++;

      if (count[name] == 1) {
        ret.push_back(name);
      } else {
        // need rename
        int nex_valid = 1;
        if (index.count(name)) {
          nex_valid = index[name];
        }
        string test = name + "(" + to_string(nex_valid) + ")";
        while (count.find(test) != count.end()) {
          nex_valid++;
          test = name + "(" + to_string(nex_valid) + ")";
        }
        // cache the index
        index[name] = nex_valid;
        // 修改过的也作为正式的输入记录
        count[test]++;
        ret.push_back(test);
      }
    }

    return ret;
  }
};
