// http://leetcode.com/problems/find-and-replace-pattern/description/
#include "xxx.hpp"

class Solution {
public:
  // order matters
  vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
    vector<string> ret;
    for (auto &s : words) {
      // 要找不到都找不到，找到还必须和之前配对的相等
      unordered_map<char, char> permu;
      unordered_set<char> valueset;
      int i = 0;
      for (i = 0; i < s.size(); i++) {
        // 没找到
        if (permu.find(s[i]) == permu.end()) {
          if (valueset.find(pattern[i]) == valueset.end()) {
            // 都没找到，建立关系
            permu[s[i]] = pattern[i];
            valueset.insert(pattern[i]);
          } else {
            // value有对应关系了，而key s[i]没有
            break;
          }
        } else {
          // 找到了，跟之前关系不一样也不行
          if (pattern[i] != permu[s[i]]) {
            break;
          }
        }
      }
      if (i == s.size()) {
        ret.push_back(s);
      }
    }
    return ret;
  }
};

int main() {
  Solution so;
  vector<string> words{"mee"};
  so.findAndReplacePattern(words, "abb");
}
