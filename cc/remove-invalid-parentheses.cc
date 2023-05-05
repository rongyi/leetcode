// http://leetcode.com/problems/remove-invalid-parentheses/description/
#include "xxx.hpp"

class Solution {
public:
  vector<string> removeInvalidParentheses(string s) {
    vector<string> ret;
    // edited string and last modified index
    queue<pair<string, int>> q;
    q.push({s, 0});

    while (!q.empty()) {
      auto [cur, idx] = q.front();
      q.pop();
      if (isValid(cur)) {
        ret.push_back(cur);
      } else if (ret.empty()) {
        // dedup, we can use a set or
        // make deletion in a uniq way
        // 1. delete with order
        // 2. same paren, only delete the first one e.g.
        //    (((, we don't delete for the second and third '('
        for (int i = idx; i < cur.size(); i++) {
          if ((cur[i] == ')' || cur[i] == '(') &&
              (i == idx || cur[i] != cur[i - 1])) {
            q.push({cur.substr(0, i) + cur.substr(i + 1), i});
          }
        }
      }
    }

    return ret;
  }

private:
  bool isValid(string &s) {
    int cnt = 0;
    for (auto &c : s) {
      if (c == '(') {
        cnt++;
      }
      if (c == ')') {
        if (cnt > 0) {
          cnt--;
        } else {
          return false;
        }
      }
    }

    return cnt == 0;
  }
};

