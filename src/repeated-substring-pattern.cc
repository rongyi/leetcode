// http://leetcode.com/problems/repeated-substring-pattern/description/
#include "xxx.h"

class Solution {
public:
  bool repeatedSubstringPattern(string s) {
    const int n = s.size();
    if (n <= 1) {
      return false;
    }
    unordered_map<char, int> count;
    unordered_set<char> uniq;
    for (auto c : s) {
      count[c]++;
      uniq.insert(c);
    }
    // 从头开始算就可以了
    string pattern;
    unordered_set<char> ps;

    for (int i = 0; i < n / 2; ++i) {
      pattern.push_back(s[i]);
      ps.insert(s[i]);
      // 1. 能够整除
      // 2. 字符填充完毕
      if (n % pattern.size() == 0 && ps.size() == uniq.size() &&
          match(pattern, s.substr(i + 1))) {
        return true;
      }
    }
    return false;
  }

private:
  // 注意这里不一定要全部一致，比如
  // abaab，这样的a的频率可以高点，所以在判断中拿掉了这个判断
  bool allsame(string &pattern, unordered_map<char, int> &count) {
    for (int i = 1; i < pattern.size() - 1; ++i) {
      if (count[pattern[i]] != count[pattern[i - 1]]) {
        return false;
      }
    }
    return true;
  }
  bool match(string &pattern, string target) {
    const int n = pattern.size();
    const int m = target.size();

    for (int i = 0; i < m / n; i++) {
      for (int j = 0; j < n; ++j) {
        if (pattern[j] != target[i * n + j]) {
          return false;
        }
      }
    }
    return true;
  }
};

int main() {
  Solution so;
  auto ret = so.repeatedSubstringPattern("abaababaab");
  cout << ret << endl;
}
