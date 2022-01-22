// http://leetcode.com/problems/longest-uncommon-subsequence-ii/description/
#include "xxx.hpp"

class Solution {
public:
  int findLUSlength(vector<string> &strs) {
    // sort(strs.begin(), strs.end(),
    //      [](string &l, string &r) -> bool { return l.size() > r.size(); });
    unordered_set<string> duplicate;
    int ret = -1;
    // 直接暴力去做，如果发现当前字符属于某个字符的subsequence则放弃这个字符
    for (int i = 0; i < strs.size(); i++) {
      if (duplicate.find(strs[i]) != duplicate.end()) {
        continue;
      }
      int j = 0;
      for (; j < strs.size(); ++j) {
        if (i == j) {
          continue;
        }
        if (isSubsequence(strs[i], strs[j])) {
          duplicate.insert(strs[i]);
          break;
        }
      }
      // no common
      if (j == strs.size()) {
        ret = max(ret, (int)(strs[i].size()));
      }
    }
    return ret;
  }

private:
  bool isSubsequence(string s, string t) {
    if (s.empty()) {
      return true;
    }
    int j = 0;
    const int m = s.size();
    const int n = t.size();

    for (int i = 0; i < n; i++) {
      if (s[j] == t[i]) {
        j++;
      }

      if (j == m) {
        return true;
      }
    }

    return false;
  }
};
int main() {
  Solution so;
  vector<string> input{"aabbcc", "aabbcc", "cb"};
  auto ret = so.findLUSlength(input);
  cout << ret << endl;
}
