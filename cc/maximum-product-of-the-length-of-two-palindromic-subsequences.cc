// https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/
#include "xxx.hpp"

class Solution {
public:
  int maxProduct(string s) {
    int ret = 0;
    string s1{};
    string s2{};
    dfs(s, s1, s2, 0, ret);

    return ret;
  }

private:
  // s1, s2 we are not using reference
  void dfs(string &s, string s1, string s2, int pos, int &ret) {
    if (pos >= s.size()) {
      if (isParlindrome(s1) && isParlindrome(s2)) {
        ret = max({ret, (int)s1.size() * (int)s2.size()});
      }
      return;
    }
    // pick current ch to s1
    s1.push_back(s[pos]);
    dfs(s, s1, s2, pos + 1, ret);
    s1.pop_back();

    // pick current ch to s2
    s2.push_back(s[pos]);
    dfs(s, s1, s2, pos + 1, ret);
    s2.pop_back();

    // don't pick current pos at all
    dfs(s, s1, s2, pos + 1, ret);
  }

  bool isParlindrome(string &s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, --j) {
      if (s[i] != s[j]) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  string s{"leetcodecom"};
  Solution so;
  so.maxProduct(s);
}
