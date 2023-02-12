// http://www.lintcode.com/zh-cn/problem/multiply-strings
#include "xxx.hpp"

class Solution {
public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") {
      return "0";
    }
    int sz1 = num1.size();
    int sz2 = num2.size();
    string ret{};
    for (int i = sz2 - 1, shift = 0; i >= 0; --i, shift++) {
      string cur = multiplysingle(num1, num2[i], shift);
      ret = add(ret, cur);
    }
    return ret;
  }

private:
  string multiplysingle(string num1, char num2, int shift) {
    int sz = num1.size();
    ostringstream oss;
    int carry = 0;
    int m2 = num2 - '0';
    for (int i = sz - 1; i >= 0; i--) {
      int cur = num1[i] - '0';
      int mul = cur * m2 + carry;
      carry = mul / 10;
      oss << (mul % 10);
    }
    if (carry) {
      oss << carry;
    }
    string ret = oss.str();
    reverse(ret.begin(), ret.end());

    return ret + string(shift, '0');
  }

  string add(string num1, string num2) {
    int sz1 = num1.size();
    int sz2 = num2.size();
    int carry = 0;

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    ostringstream oss;
    for (int i = 0; i < max(sz1, sz2); i++) {
      int sum = carry;
      if (i < sz1) {
        sum += (num1[i] - '0');
      }
      if (i < sz2) {
        sum += (num2[i] - '0');
      }
      oss << (sum % 10);
      carry = sum / 10;
    }
    if (carry) {
      oss << carry;
    }
    string ret = oss.str();
    reverse(ret.begin(), ret.end());
    return ret;
  }
};

int main() {
  Solution so;
  auto ret = so.multiply("0", "52");
  cout << ret << endl;
}
