// http://leetcode.com/problems/keyboard-row/description/
#include "xxx.hpp"

class Solution {
public:
  vector<string> findWords(vector<string> &words) {
    vector<string> ret;
    string top_row{"qwertyuiop"};
    string mid_row{"asdfghjkl"};
    string bottom_row{"zxcvbnm"};
    for (auto c : top_row) {
      row_[c] = 0;
    }
    for (auto c : mid_row) {
      row_[c] = 1;
    }
    for (auto c : bottom_row) {
      row_[c] = 2;
    }

    for (auto s : words) {
      if (ok(s)) {
        ret.push_back(s);
      }
    }

    return ret;
  }

private:
  bool ok(string &s) {
    bool has_upper = false;
    bool has_lower = false;
    unordered_set<int> rows;
    for (auto c : s) {
      if (islower(c)) {
        has_lower = true;
        rows.insert(row_[c]);
      } else {
        has_upper = true;
        rows.insert(row_[tolower(c)]);
      }
    }

    if (rows.size() > 1) {
      return false;
    }
    // 考虑多了，不用考虑capslock的情况
    // // 为1的情况还要看是否有大写，如果有大写，只能是中间和下面两层的，不能是最上层
    // // 因为大写可以用 capslock或者shift来实现
    // if (has_upper && *rows.begin() == 0) {
    //   return false;
    // }

    return true;
  }
private:
  unordered_map<char, int> row_;
};

int main() {
  Solution so;
  vector<string> input{"Hello", "Alaska", "Dad", "Peace"};
  auto ret = so.findWords(input);
  for (auto s : ret) {
    cout << s << " ";
  }
  cout << endl;
}
