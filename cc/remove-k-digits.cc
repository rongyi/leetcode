// http://leetcode.com/problems/remove-k-digits/description/
#include "xxx.hpp"

class Solution {
public:
  string removeKdigits(string num, int k) {
    // 其实就是尽量让小的进来，如果发现有小的，那么大的就让位
    string ret{};
    for (auto c : num) {
      while (!ret.empty() && ret.back() > c && k) {
        ret.pop_back();
        k--;
      }

      if (!ret.empty() || c != '0') {
        ret.push_back(c);
      }
    }

    while (!ret.empty() && k) {
      ret.pop_back();
      k--;
    }

    return ret.empty() ? "0" : ret;
  }
};
int main() {
  Solution so;

  auto ret = so.removeKdigits("112", 1);

  cout << ret << endl;
}
