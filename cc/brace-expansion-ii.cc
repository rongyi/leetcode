// http://leetcode.com/problems/brace-expansion-ii/description/
#include "xxx.hpp"

class Solution {
public:
  // 卡在怎么串起来的过程中
  vector<string> braceExpansionII(string expression) {
    int i = 0;
    auto ret = parseRule2(expression, i);

    return vector<string>(ret.begin(), ret.end());
  }
private:
  set<string> merge(set<string> &a, set<string> &b) {
    if (a.empty()) {
      return b;
    }
    if (b.empty()) {
      return a;
    }
    set<string> ret;
    for (auto &v1 : a) {
      for (auto &v2 : b) {
        ret.insert(v1 + v2);
      }
    }

    return ret;
  }

  // {a, b, c}
  set<string> parseRule1(const string &str, int &i) {
    set<string> ret;

    // ignore {
    i++;

    ret = parseRule2(str, i);

    // ignore }
    i++;
    return ret;
  }
  // {a,b},{c,d}
  set<string> parseRule2(const string &str, int &i) {
    set<string> ret;
    ret = parseRule3(str, i);

    while (i < str.size()) {
      if (str[i] != ',') {
        break;
      }
      i++;
      set<string> tmp = parseRule3(str, i);
      ret.insert(tmp.begin(), tmp.end());
    }

    return ret;
  }

  // a{c,d}b{e,f}
  set<string> parseRule3(const string &str, int &i) {
    set<string> ret;
    while (i < str.size()) {
      if (str[i] == '}' || str[i] == ',') {
        break;
      }
      if (str[i] == '{') {
        set<string> tmp = parseRule1(str, i);
        ret = merge(ret, tmp);
      } else {
        set<string> tmp;
        string cur;
        while (i < str.size() && str[i] <= 'z' && str[i] >= 'a') {
          cur.push_back(str[i++]);
        }
        tmp.insert(cur);
        ret = merge(ret, tmp);
      }
    }

    return ret;
  }
};
