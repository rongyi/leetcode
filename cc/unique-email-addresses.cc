// http://leetcode.com/problems/unique-email-addresses/description/
#include "xxx.h"

class Solution {
public:
  int numUniqueEmails(vector<string> &emails) {
    auto fn = [](string &e) -> string {
      string local{};
      // 这样少一次拷贝
      // string domain = e.substr(e.find('@')); // '@' included
      for (auto c : e) {
        if (c == '+' || c == '@') {
          break;
        }
        if (c == '.') {
          continue;
        }
        local.push_back(c);
      }
      return local + e.substr(e.find('@'));
    };

    unordered_set<string> uniq;
    for (auto &e : emails) {
      uniq.insert(fn(e));
    }
    return uniq.size();
  }
};
