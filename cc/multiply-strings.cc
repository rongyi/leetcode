// http://www.lintcode.com/zh-cn/problem/multiply-strings
#include "xxx.hpp"

class Solution {
public:
  string multiply(string num1, string num2) {
    const int n = num2.size();
    vector<string> mapmulti;
    // 1234 * 2 ==>
    // 1 * 2 then shift 000
    // 2 * 2 then shift 00
    // 3 * 2 then shift 0
    // 4 * 2 then shift ''
    // then add these string
    for (int i = 0; i < n; ++i) {
      auto curmul = multiplysingle(num1, num2[i]);
      if (curmul == "") {
        continue;
      }
      // should also add shift '0'
      // 我们从最高位的num2开始计算，所以这里对应的在后面添0，个数看后面还有几个数字
      curmul += string(n - i - 1, '0');

      mapmulti.push_back(curmul);
    }

    if (mapmulti.size() == 0) {
      return "0";
    } else if (mapmulti.size() == 1) {
      return mapmulti[0];
    }

    // now reduce
    string ret = mapmulti[0];
    for (int i = 1; i < mapmulti.size(); ++i) {
      ret = add(ret, mapmulti[i]);
    }

    return ret;
  }

private:
  string multiplysingle(string num1, char num2) {
    if (num2 == '0') {
      return "";
    }
    const int n = num1.size();
    int carry = 0;
    stringstream ss;
    for (int i = n - 1; i >= 0; --i) {
      int mul = carry + (num1[i] - '0') * (num2 - '0');
      carry = mul / 10;
      mul %= 10;
      ss << mul;
    }
    if (carry > 0) {
      ss << carry;
    }
    auto ret = ss.str();
    reverse(ret.begin(), ret.end());
    if (ret.size() > 0 && ret[0] == '0') {
      return "";
    }

    return ret;
  }

  string add(string num1, string num2) {
    const int m = num1.size();
    const int n = num2.size();
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    int carry = 0;
    stringstream ss;
    int i = 0;
    for (; i < n && i < m; ++i) {
      int sum = (num1[i] - '0') + (num2[i] - '0') + carry;
      carry = sum / 10;
      sum %= 10;
      ss << sum;
    }
    while (i < m) {
      int sum = (num1[i++] - '0') + carry;
      carry = sum / 10;
      sum %= 10;
      ss << sum;
    }
    while (i < n) {
      int sum = (num2[i++] - '0') + carry;
      carry = sum / 10;
      sum %= 10;
      ss << sum;
    }
    if (carry > 0) {
      ss << carry;
    }

    auto ret = ss.str();
    reverse(ret.begin(), ret.end());
    return ret;
  }
};

int main() {
  Solution so;
  auto ret = so.multiply("0", "52");
  cout << ret << endl;
}
