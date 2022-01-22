// http://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
#include "xxx.hpp"
class Solution {
public:
  Solution() {
    cd_map_.clear();

    cd_map_.insert({2, vector<char>{'a', 'b', 'c'}});
    cd_map_.insert({3, vector<char>{'d', 'e', 'f'}});
    cd_map_.insert({4, vector<char>{'g', 'h', 'i'}});
    cd_map_.insert({5, vector<char>{'j', 'k', 'l'}});
    cd_map_.insert({6, vector<char>{'m', 'n', 'o'}});
    cd_map_.insert({7, vector<char>{'p', 'q', 'r', 's'}});
    cd_map_.insert({8, vector<char>{'t', 'u', 'v'}});
    cd_map_.insert({9, vector<char>{'w', 'x', 'y', 'z'}});
  }
  vector<string> letterCombinations(string digits) {
    const int n = digits.size();
    vector<string> ret;
    if (n == 0) {
      return ret;
    }
    if (n == 1) {
      vector<string> tmp;

      return reduce(cd_map_[digits[0] - '0'], tmp);

    } else if (digits.size() == 2) {
      return map(cd_map_[digits[0] - '0'], cd_map_[digits[1] - '0']);
    } else {
      // lisp name convention
      string cdr = digits.substr(1);
      auto cdr_ret = letterCombinations(cdr);
      return reduce(cd_map_[digits[0] - '0'], cdr_ret);
    }

    return ret;
  }

private:
  vector<string> map(const vector<char> &left, const vector<char> &right) {
    vector<string> ret;
    for (const auto &l : left) {
      string cur;
      cur.push_back(l);
      for (const auto &r : right) {
        cur.push_back(r);
        ret.push_back(cur);
        cur.pop_back();
      }
    }

    return ret;
  }

  vector<string> reduce(const vector<char> &left, vector<string> &acc) {
    vector<string> ret;
    for (const auto &l : left) {
      if (acc.empty()) {
        ret.push_back({l});
      } else {
        for (const auto &s : acc) {
          string cur{l};
          cur += s;
          ret.push_back(cur);
        }
      }
    }

    return ret;
  }

private:
  // cellphone digit map
  unordered_map<char, vector<char>> cd_map_;
};

int main() {
  Solution so;
  auto ret = so.letterCombinations("2");
  for (auto s : ret) {
    cout << s << endl;
  }
}
