// http://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
#include "xxx.hpp"
class Solution {
public:
  Solution() {
    cd_map_.clear();

    cd_map_.insert({'2', vector<char>{'a', 'b', 'c'}});
    cd_map_.insert({'3', vector<char>{'d', 'e', 'f'}});
    cd_map_.insert({'4', vector<char>{'g', 'h', 'i'}});
    cd_map_.insert({'5', vector<char>{'j', 'k', 'l'}});
    cd_map_.insert({'6', vector<char>{'m', 'n', 'o'}});
    cd_map_.insert({'7', vector<char>{'p', 'q', 'r', 's'}});
    cd_map_.insert({'8', vector<char>{'t', 'u', 'v'}});
    cd_map_.insert({'9', vector<char>{'w', 'x', 'y', 'z'}});
  }
  vector<string> letterCombinations(string digits) {
    cache_.clear();
    recur(digits, "");

    return cache_;
  }

private:
  void recur(string d, string acc) {
    if (d.empty()) {
      if (!acc.empty()) {
        cache_.push_back(acc);
      }
      return;
    }
    for (auto &c : cd_map_[d[0]]) {
      string tmp = acc + c;
      recur(d.substr(1), tmp);
    }
  }

private:
  // cellphone digit map
  unordered_map<char, vector<char>> cd_map_;
  vector<string> cache_;
};

