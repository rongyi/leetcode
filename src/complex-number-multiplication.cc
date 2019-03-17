// http://leetcode.com/problems/complex-number-multiplication/description/
#include "xxx.h"

class Solution {
public:
  string complexNumberMultiply(string c1, string c2) {
    auto a = realPart(c1);
    auto b = virtualPart(c1);

    auto c = realPart(c2);
    auto d = virtualPart(c2);

    // 乘法展开即可
    auto real_part = a * c - b * d;
    auto virtual_part = a * d + b * c;
    stringstream ss;
    ss << real_part << "+" << virtual_part << "i";

    return ss.str();
  }

public:
  int virtualPart(string &a) {
    // jump over real part
    int i = 0;
    // ignore the real part sign
    if (a[i] == '+' || a[i] == '-') {
      i++;
    }
    // then ignore the real part digit
    while (i < a.size() && isdigit(a[i])) {
      i++;
    }
    // ignore the plus sign
    i++;
    if (a[i] == 'i') {
      return 1;
    }

    // now the valid imaginary part
    bool is_negative = false;
    if (a[i] == '+') {
      i++;
    } else if (a[i] == '-') {
      i++;
      is_negative = true;
    }
    int start = i;
    // till we meet the i sign
    while (i < a.size() && a[i] != 'i') {
      i++;
    }
    string vir_str = a.substr(start, i - start);
    auto ret = stoi(vir_str);
    if (is_negative) {
      ret = -ret;
    }

    return ret;
  }
  int realPart(string &a) {
    bool is_negative = false;
    int i = 0;
    if (a[i] == '+') {
      i++;
    } else if (a[i] == '-') {
      is_negative = true;
      i++;
    }
    int start = i;

    while (i < a.size() && isdigit(a[i])) {
      i++;
    }
    auto real_str = a.substr(start, i - start);
    auto ret = stoi(real_str);
    if (is_negative) {
      ret = -ret;
    }
    return ret;
  }
};

int main() {
  Solution so;
  string input{"-123+99i"};
  // auto real = so.realPart(input);
  // cout << real << endl;

  auto real = so.virtualPart(input);
  cout << real << endl;
}
