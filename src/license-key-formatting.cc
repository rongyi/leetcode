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
    // 总共1个字符分成两段？
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
      return injectDash(pure, k);
    }
    // 否则第一排的就是零头
    stringstream ss;
    auto left = normal % k;
    ss << pure.substr(0, left) << '-';
    pure = pure.substr(left);

    ss << injectDash(pure, k);

    return ss.str();
  }

private:
  string injectDash(string &pure, const int k) {
    stringstream ss;

    const int round = pure.size() / k;
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
  auto ret = so.licenseKeyFormatting("5F3Z-2e-9-w", 4);
  cout << ret << endl;
}
