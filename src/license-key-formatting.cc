// http://leetcode.com/problems/license-key-formatting/description/
#include "xxx.h"

class Solution {
public:
  string licenseKeyFormatting(string s, int k) {
    const int n = s.size();
    // dash在重排过程中没什么用
    int dash_count = count(s.begin(), s.end(), '-');
    int normal = n - dash_count;

    // 一些特殊条件
    if (normal == 0) {
      return "";
    }
    if (k > normal) {
      k = normal;
    }

    // making a pureset
    string pure;
    for (auto c : s) {
      if (c != '-') {
        if (isdigit(c) || isupper(c)) {
          pure.push_back(c);
        } else {
          pure.push_back(toupper(c));
        }
      }
    }

    // 正好
    if (normal % k == 0) {
      stringstream ss;

      auto round = normal / k;
      for (int i = 0; i < round; i++) {
        ss << pure.substr(i * k, k);

        if (i != round - 1) {
          ss << '-';
        }
      }
      return ss.str();
    }
    // 否则第一排的就是零头
    stringstream ss;
    auto left = normal % k;
    ss << pure.substr(0, left) << '-';
    pure = pure.substr(left);

    auto round = normal / k;
    for (int i = 0; i < round; i++) {
      ss << pure.substr(i * k, k);

      if (i != round - 1) {
        ss << '-';
      }
    }

    return ss.str();
  }
};
int main() {
  Solution so;
  auto ret = so.licenseKeyFormatting("2", 2);
  cout << ret << endl;
}
