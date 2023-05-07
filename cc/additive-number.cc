// https://leetcode.com/problems/additive-number/
#include "xxx.hpp"

class Solution {
public:
  bool isAdditiveNumber(string num) { return recur(num, 0, "", ""); }
  bool recur(string &s, int pos, string prev1, string prev2) {
    // fresh start, no prev1, prev2
    int sz = s.size();
    if (pos == 0) {
      // at least give prev1 a digit
      // and the prev2
      // gap index start from zero
      for (int l1 = 1; 0 + l1 <= sz - 2; l1++) {
        for (int l2 = 1; l1 + l2 <= sz - 1; l2++) {
          string s1 = s.substr(0, l1);
          string s2 = s.substr(l1, l2);
          // no leading zero
          if (s2.size() > 1 && s2[0] == '0') {
            continue;
          }
          // cout << s1 << " | " << s2 << " | " << endl;
          if (recur(s, l1 + l2, s1, s2)) {
            return true;
          }
        }
      }
    } else {
      string peek = addStrings(prev1, prev2);
      if (pos >= sz || pos + peek.size() > sz) {
        return false;
      }
      // final match
      if (pos + peek.size() == sz && s.substr(pos) == peek) {
        return true;
      }
      if (pos + peek.size() < sz && s.substr(pos, peek.size()) == peek) {
        return recur(s, pos + peek.size(), prev2, s.substr(pos, peek.size()));
      }
      return false;
    }

    return false;
  }

private:
  // steal from add string
  string addStrings(string num1, string num2) {
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    int carry = 0;
    const int m = num1.size();
    const int n = num2.size();

    stringstream ss;
    for (int i = 0; i < m || i < n || carry; ++i) {
      int sum = carry;
      if (i < m) {
        sum += num1[i] - '0';
      }
      if (i < n) {
        sum += num2[i] - '0';
      }
      ss << sum % 10;

      carry = sum / 10;
    }

    string ret = ss.str();
    reverse(ret.begin(), ret.end());

    return ret;
  }
};

int main() {
  Solution so;
  auto ret = so.isAdditiveNumber("199001200");
  cout << ret << endl;
}
